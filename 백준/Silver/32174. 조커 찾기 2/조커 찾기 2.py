import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n, m = map(int, input().split())
arr = [0]
for i in range(m):
    a, b = map(int, input().split())
    if a == 1:
        arr.append((arr[-1] + b) % n)
    elif a == 2:
        arr.append((arr[-1] - b) % n)
    else:
        arr.append(arr[b])

print(arr[-1] + 1)