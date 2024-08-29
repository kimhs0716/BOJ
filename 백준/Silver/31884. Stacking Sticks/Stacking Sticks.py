import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
d = dict()
for _ in range(n):
    c, i = map(int, input().split())
    if c == 2:
        d[i] = d.get(i, 0) + 4
    elif c == 1:
        M = max(map(lambda x: d.get(x, 0), range(i, i + 4))) + 1
        for j in range(i, i + 4): d[j] = M
    else:
        print(d.get(i, 0))
    # print(d)
