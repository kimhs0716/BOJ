import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


def find(arr, x):
    m, M = 0, len(arr)
    while True:
        mid = (m + M + 1) // 2
        if arr[mid][0] < x < arr[mid + 1][0]:
            return mid + 1
        if arr[mid - 1][0] < x < arr[mid][0]:
            return mid
        if x < arr[mid][0]: M = mid
        else: m = mid

n = int(input())
x, y = map(int, input().split())
cur = y
arr = [(x, 0)]
for _ in range(n - 1):
    x, y = map(int, input().split())
    if y < cur: t = -1
    elif y > cur: t = 1
    else: t = 0
    arr.append((x, t))
    cur = y

q = int(input())
for _ in range(q):
    x = float(input())
    print(arr[find(arr, x)][1])
