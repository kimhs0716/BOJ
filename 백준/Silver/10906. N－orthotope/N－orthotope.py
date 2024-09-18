import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

cnt = 0
ans = 0
for i in range(n):
    s1, e1 = arr1[2 * i], arr1[2 * i + 1]
    s2, e2 = arr2[2 * i], arr2[2 * i + 1]
    if max(s1, s2) < min(e1, e2):
        cnt += 1
    elif max(s1, s2) == min(e1, e2):
        cnt += 0
    else:
        ans = -1

if ans != -1:
    ans = cnt
print(ans)
