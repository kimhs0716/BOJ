import sys

try:
    sys.stdin = open("boj.in", "r", encoding="utf-8")
    sys.stdout = open("boj.out", "w", encoding="utf-8")
except:
    pass

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

INF = float('inf')


from functools import cache

@cache
def score(idx, s):
    global arr
    if idx==-1: return (0, 0)
    ret = (0, s)
    cs = 0
    for i in range(idx, -1, -1):
        cs += arr[i]
        a, b = score(i-1, s-cs)
        ret = max(ret, (b+arr[i], a+cs - arr[i]))
    return ret

def preprocess():
    pass

arr = []
def solve():
    global arr
    n = int(input())
    arr = list(map(int, input().split()))
    print(score(n-1, sum(arr))[0])

def main():
    preprocess()
    tc = 1
    # tc = int(input())
    for _ in range(tc):
        solve()

if __name__ == "__main__":
    main()