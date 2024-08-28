import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
arr = [int(input()) for _ in range(n)]
two = set()
for i in arr:
    for j in arr:
        two.add(i + j)

ans = 0
for i in arr:
    for j in arr:
        if i - j in two:
            ans = max(ans, i)
print(ans)

