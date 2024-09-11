import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

from collections import Counter

def key(s):
    global yeondu
    c = Counter(s)
    L, O, V, E = map(lambda x: yeondu.get(x, 0), 'LOVE')
    l, o, v, e = map(lambda x: c.get(x, 0), 'LOVE')
    L += l
    O += o
    V += v
    E += e
    return ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100

yeondu = Counter(input())
n = int(input())
arr = [input() for _ in range(n)]
arr.sort()
arr.sort(key=key, reverse=True)
print(arr[0])
