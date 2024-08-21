import sys
input = lambda: sys.stdin.readline().rstrip()

mod = int(1e9 + 7)

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
sq = [1]
for i in range(n):
    sq.append(sq[-1] * 2 % mod)
ans = 0

for i in range(n):
    ans = (ans + (sq[i] - sq[n - i - 1]) * arr[i]) % mod

print(ans)
