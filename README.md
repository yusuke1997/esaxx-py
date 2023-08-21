# esaxx-py

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![Python versions](https://img.shields.io/badge/python-3.7%20%7C%203.8%20%7C%203.9%20%7C%203.10%20%7C%203.11-blue)
[![Python package](https://github.com/yusuke1997/esaxx-py/actions/workflows/python-package.yaml/badge.svg)](https://github.com/yusuke1997/esaxx-py/actions/workflows/python-package.yaml)


Python wrapper of the Enhanced Suffix Array (ESA).

This is a version adapted for Python, originating from the C++ implementation found [here](https://github.com/hillbig/esaxx).

## Installation

```bash
pip install esaxx-py
```

## Usage

```python
from esa import esaxx

def print_snippet(T, beg, length):
    for i in range(length):
        c = T[beg + i]
        print("_" if c.isspace() else c, end="")

T = 'abracadabra'
SA = [0]*len(T)
L = [0]*len(T)
R = [0]*len(T)
D = [0]*len(T)
    
k = 0x100
node_num = 0
node_num = esaxx(T, SA, L, R, D, orig_len, k, node_num)
if node_num == -1:
    exit()

print(f"node:{node_num}")

for i in range(node_num):
    print(f"{i}\t{R[i] - L[i]}\t{D[i]}\t", end="")
    print_snippet(T, SA[L[i]], D[i])
    print()
```
```bash
node:5
0	2	4	abra
1	5	1	a
2	2	3	bra
3	2	2	ra
4	11	0
```

Alternatively, you can use enumSubstring.py:
```bash
ehco abracadabra | python enumSubstring.py
```

For the original implementation:
```bash
g++ enumSubstring.cpp
echo abracadabra | ./a.out
```

### Note
In the original implementation, the return value of esaxx was an error code, not node_num.
However, due to the constraints of Python and the difficulty in passing by reference, I've chosen to return node_num.


## Maximal Substrings

To obtain Maximal Substrings:
```python
from esa import esaxx

def print_snippet(T, beg, length):
    for i in range(length):
        c = T[beg + i]
        print("_" if c.isspace() else c, end="")

T = 'abracadabra'
SA = [0]*len(T)
L = [0]*len(T)
R = [0]*len(T)
D = [0]*len(T)
    
k = 0x100
node_num = 0
node_num = esaxx(T, SA, L, R, D, orig_len, k, node_num)
if node_num == -1:
    exit()

size = len(T)

# Record changes in BWT
rank = [0] * size
r = 0
for i in range(size):
    if i == 0 or T[(SA[i] + size - 1) % size] != T[(SA[i - 1] + size - 1) % size]:
        r += 1
    rank[i] = r
    
print("count\tlength\tstring")
# Enumerate maximal partial strings
for i in range(node_num):
    if D[i] == 0 or (rank[R[i] - 1] - rank[L[i]] == 0):
        continue
    print(f"{R[i] - L[i]}\t{D[i]}\t", end="")
    print_snippet(T, SA[L[i]], D[i])
    print()
```

```bash
count	length	string
2	4	abra
5	1	a
```

enumMaxSubstring.py:
```bash
ehco abracadabra | python enumMaxSubstring.py
```
C++ (enumMaxSubstring.cpp):
```
g++ enumMaxSubstring.cpp
echo abracadabra | ./a.out
```


## Additional Information

C++ Implementation:

- https://github.com/hillbig/esaxx
- https://code.google.com/archive/p/esaxx/
- https://github.com/TNishimoto/esaxx

Rust Version:

- https://github.com/Narsil/esaxx-rs/

Software using esaxx:

- https://github.com/huggingface/tokenizers
- https://github.com/google/sentencepiece
- https://github.com/shuyo/ldig
- http://phontron.com/pialign/

List of papers using esaxx:
- https://ipsj.ixsq.nii.ac.jp/ej/index.php?active_action=repository_view_main_item_detail&page_id=13&block_id=8&item_id=47681&item_no=1
- https://www.anlp.jp/proceedings/annual_meeting/2012/pdf_dir/A3-1.pdf
- https://www.anlp.jp/proceedings/annual_meeting/2012/pdf_dir/D5-2.pdf

Articles about `esaxx`:

- https://tech.retrieva.jp/entry/2021/11/02/115816
- https://shogo82148.hatenablog.com/entry/20110916/1316172382
- https://takeda25.hatenablog.jp/entry/20101202/1291269994
- https://blog.shibayu36.org/entry/2017/01/28/150033