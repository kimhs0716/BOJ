import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n = int(input())
arr = list(map(int, input().split()))
k = int(input())
sarr = [0]
for i in range(n):
    sarr.append(sarr[-1] + arr[i])

# print(sarr)

ans = 0
i, j = 0, 1
while j <= n:
    while i < j and sarr[j] - sarr[i] > k:
        i += 1
    ans += i
    j += 1
    # print(i, j, ans)

print(ans)
