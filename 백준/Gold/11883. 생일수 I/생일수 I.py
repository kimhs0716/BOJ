import sys

try:
    sys.stdin = open("boj.in", "r", encoding="utf-8")
    sys.stdout = open("boj.out", "w", encoding="utf-8")
except:
    pass

input = lambda: sys.stdin.readline().rstrip()

INF = float('inf')
MAX = 1_000_000


def better(a, b):
    if a[0] < b[0]: return a
    if a[0] > b[0]: return b
    if a[1] < b[1]: return b
    if a[1] > b[1]: return a
    if a[2] < b[2]: return b
    else: return a

def add(a, b):
    return tuple(a[i]+(b==i or i==0) for i in range(4))

dp = [(INF, 0, 0, 0)] * (MAX+1)
def preprocess():
    dp[0] = (0, 0, 0, 0)
    for i in range(1, MAX+1):
        if i>=3: dp[i] = better(dp[i], add(dp[i-3], 1))
        if i>=5: dp[i] = better(dp[i], add(dp[i-5], 2))
        if i>=8: dp[i] = better(dp[i], add(dp[i-8], 3))

def solve():
    n = int(input())
    if dp[n][0] == INF: print(-1)
    else: print("3"*dp[n][1] + "5"*dp[n][2] + "8"*dp[n][3])

def main():
    preprocess()
    for _ in range(int(input())):
        solve()

if __name__ == "__main__":
    main()