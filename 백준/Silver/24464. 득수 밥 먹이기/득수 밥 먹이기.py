import sys
input = lambda: sys.stdin.readline()[:-1]

mod = int(1e9+7)
n = int(input())
ans = [1] * 5
for i in range(n - 1):
    new = [
        sum(ans) - ans[0],
        ans[0] + ans[3] + ans[4],
        ans[0] + ans[4],
        ans[0] + ans[1],
        ans[0] + ans[1] + ans[2]
    ]
    for i in range(5): new[i] %= mod
    ans = new

print(sum(ans) % mod)
