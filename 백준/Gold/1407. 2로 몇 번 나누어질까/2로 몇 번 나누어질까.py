import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

def naive(n, m):
    return naive2(m) - naive2(n - 1)

def naive2(n):
    ret = 0
    for i in range(1, n + 1):
        cnt = 0
        while i % 2 == 0:
            cnt += 1
            i >>= 1
        ret += 1 << cnt
    return ret

def calc(n):
    if n == 0: return 0
    if n == 1: return 1
    if n == 2: return 3
    t = 1
    cnt = 0
    while t <= n:
        t <<= 1
        cnt += 1
    t >>= 1
    # print(n, cnt, t, dp[cnt])
    return dp[cnt - 1][0] + calc(n - t)

dp = [[1, 1]]
t = 2
for i in range(50):
    _, b = dp[-1]
    a = b + t
    b += a
    dp.append([a, b])
    t <<= 1

# print(dp)

def solve(n, m):
    return calc(m) - calc(n - 1)

n, m = map(int, input().split())
print(solve(n, m))

# import random
# for _ in range(10):
#     a = random.randint(1, 1000)
#     b = random.randint(a, 1000)
#     if naive(a, b) != solve(a, b):
#         print(a, b, solve(a, b), naive(a, b))
#         pass