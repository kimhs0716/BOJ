import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


n, m = map(int, input().split())
k = 0
ans = [[0] * m for _ in range(n)]

if n == 1:
    if m == 1:
        k = 1
        ans[0][0] = 1
    else:
        k = 2
        for i in range(m):
            ans[0][i] = 1 if i % 2 == 0 else 2

else:
    if m == 1:
        k = 2
        for i in range(n):
            ans[i][0] = 1 if i % 2 == 0 else 2
    else:
        k = 4
        for i in range(n):
            for j in range(m):
                ans[i][j] = (1 if j % 2 == 0 else 2) + (0 if i % 2 == 0 else 2)

print(k)
for i in ans:
    print(*i)
