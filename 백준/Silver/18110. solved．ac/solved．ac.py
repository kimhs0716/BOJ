import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
ex = int(n * 15 / 100 + 0.5)

arr = [int(input()) for _ in range(n)]
n -= 2 * ex
arr.sort()
arr = arr[ex:-ex] if ex else arr

s = sum(arr)
print(int(s / n + 0.5) if n else 0)
