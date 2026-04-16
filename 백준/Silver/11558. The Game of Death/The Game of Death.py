import sys
input = lambda: sys.stdin.readline()[:-1]

def solve(n, arr):
    k = 0
    cur = 1
    for _ in range(n):
        if cur == n: 
            print(k)
            return
        cur = arr[cur - 1]
        k += 1
    print(0)

for _ in range(int(input())):
    n = int(input())
    assert n >= 2
    arr = [ int(input()) for _ in range(n) ]
    solve(n, arr)
