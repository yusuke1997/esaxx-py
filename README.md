# esaxx-py

Enhanced Suffix Array (ESA) の Python 実装。

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![Python versions](https://img.shields.io/badge/python-3.7%20%7C%203.8%20%7C%203.9%20%7C%203.10%20%7C%203.11-blue)


## インストール

```
pip install esaxx-py
```

## 使用方法

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

あるいは`numSubstring.py`を用いて
```bash
ehco abracadabra | python numSubstring.py
```

オリジナルの実装では
```bash
g++ enumSubstring.cpp
echo abracadabra | ./a.out
```

## ライセンス

このプロジェクトは MIT ライセンスのもとでライセンスされています。詳細については `LICENSE` ファイルを参照してください。


