# esaxx-pyの作り方



## 方針

色々入り組んでたので、cythonを用いることにした。



## やり方

基本的にesa.pyxに書き込んでいくスタイル。
だけど、元のesa.hxxはテンプレート関数なので、一旦ラップしてあげる必要あるっぽい。
なので、esa_wrapper.hxxというファイルを作って、それを媒介させている。
（もっといい方法があるかもしれない）

enumSubstring.pyに色々使い方書いてる。
基本的にはesaxxの元のenumSubstring.cppを忠実に再現しているだけ。
必要ない関数とか間違っていそうな部分は削除した。

一個注意点として、esaxxではnumNodeが参照渡しされているけど、
pythonではどうしようもなかったので、仕方なく戻り値にnode_numを指定している。

もっと具体的に言えば、ソースコード確認しても結局エラーコードは-1と-2で、0以上は正常、
さらにnum_nodeの数とエラーコードの意味がほぼ一致しちゃってるので、
あんまよくないけど、仕方ないので一緒にして、戻り値をnum_nodeにした。

だからesaxxの実装色々見ていくと、sentencepieceではCHECK_EQで実行できたか確認しているが、
このコードでは通らなくなってしまう。
大小で比較になるが、戻り値の設定とか色々考えると、一番変更点が少ないのよね...


```bash
 python setup.py build_ext --inplace
```

でinstallできる。

```bash
$ echo abracadabra | python enumSubstring.py
origN: 12
    n: 11
alpha: 256
Input T: abracadabra
Input n: 11
Input k: 256
Before processing, SA: 0 0 0 0 0 0 0 0 0 0 0 
Before processing, L: 0 0 0 0 0 0 0 0 0 0 0 
Before processing, R: 0 0 0 0 0 0 0 0 0 0 0 
Before processing, D: 0 0 0 0 0 0 0 0 0 0 0 
Before processing, T.begin(): a
Before processing, SA.begin(): 0
Before processing, L.begin(): 0
Before processing, R.begin(): 0
Before processing, D.begin(): 0
After processing, SA: 10 7 0 3 5 8 1 4 6 9 2 
After processing, L: 1 0 5 9 0 0 3 0 0 0 2 
After processing, R: 3 5 7 11 11 1 0 1 0 0 0 
After processing, D: 4 1 3 2 0 0 0 0 0 0 0 
Output nodeNum: 5
node:5
0	2	4	abra
1	5	1	a
2	2	3	bra
3	2	2	ra
4	11	0	

```

となるはず。

あとはゴリゴリ修正すればいいや。