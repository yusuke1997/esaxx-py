#include <iostream>
#include "esa.hxx"
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

using namespace std;

int esaxx_wrapper(const std::string T,
                  std::vector<int>& SA,
                  std::vector<int>& L,
                  std::vector<int>& R,
                  std::vector<int>& D,
                  int n, int k, int& nodeNum) {
    
    int err =  esaxx(T.begin(), SA.begin(), L.begin(), R.begin(), D.begin(), n, k, nodeNum);

    return err;
}



// ここから、MaxStringを取得する方法
std::string convertToUtf8(const std::string& input) {
    icu::UnicodeString unicodeStr(input.c_str(), "UTF-8");
    std::string utf8;
    unicodeStr.toUTF8String(utf8);
    return utf8;
}

struct Result {
  vector<int> count;
  vector<int> length;
  vector<string> substring;
};


int getID(const string& str, map<string, int>& word2id){
  map<string, int>::const_iterator it = word2id.find(str);
  if (it == word2id.end()){
    int newID = (int)word2id.size();
    word2id[str] = newID;
    return newID;
  } else {
    return it->second;
  }
}

string convertSubstring(const vector<int>& T, int beg, int len, const vector<string>& id2word) {
  stringstream ss;
  for (int i = 0; i < len; ++i) {
    int c = T[beg + i];
    if (id2word.size() > c) {
      ss << id2word[c] << " ";
    } else {
      ss << (isspace((char)c) ? '_' : (char)c);
    }
  }
  cerr << "substring:" << ss.str() << endl;
  return ss.str();
}


Result getSubstring(const std::string& original_sent){

  Result res;

  string sent = convertToUtf8(original_sent);
    
  vector<int> T;
  map<string, int> word2id;
  size_t origLen = 0;
  for (char c : sent) {
    std::string s(1, c);
    T.push_back(getID(s, word2id));
    ++origLen;
  }

  vector<string> id2word(word2id.size());
  for (map<string, int>::const_iterator it = word2id.begin();
       it != word2id.end(); ++it){
    id2word[it->second] = it->first;
  }

  vector<int> SA(T.size());
  vector<int> L (T.size());
  vector<int> R (T.size());
  vector<int> D (T.size());

  int k = (int)id2word.size();
  cerr << "origN:" << origLen << endl;
  cerr << "    n:" << T.size() << endl;
  cerr << "alpha:" << k        << endl;

  int nodeNum = 0;
  if (esaxx(T.begin(), SA.begin(), 
	    L.begin(), R.begin(), D.begin(), 
	    (int)T.size(), k, nodeNum) == -1){
    return res;
  }

  cerr << " node:" << nodeNum << endl;

  // エラーチェック
  if (nodeNum <= 0) {
    cerr << "Error in processing" << endl;
    return res; // 空のResultを返す
  }
  
  for (int i = 0; i < nodeNum; ++i) {
    res.count.push_back(R[i] - L[i]);
    res.length.push_back(D[i]);
    res.substring.push_back(convertSubstring(T, SA[L[i]], D[i], id2word));
  }
  
  return res;

}
