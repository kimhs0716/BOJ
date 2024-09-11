import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]

diff = 987654321

for i in range(m):
    s = [arr[j][i] for j in range(n)]
    if 'X' not in s: continue
    k = 0
    while s[k] != '#': k += 1
    j = k
    while s[j] != 'X': j -= 1
    diff = min(diff, k - j - 1)
    # print(s, j, k, k - j - 1)

new = [list('.' * m) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if arr[i][j] == '#': new[i][j] = '#'
        if arr[i][j] == 'X': new[i + diff][j] = 'X'

for i in new:
    print(''.join(i))
