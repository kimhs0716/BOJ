import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

def pprint(arr):
    for i in arr:
        print(*i)

n, m = map(int, input().split())
arr = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a][b] = 1
    arr[a][0] += 1
    arr[0][b] += 1

ans = 0
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        cnt = 0
        for k in range(1, n + 1):
            if arr[i][k] and arr[j][k]: cnt += 1
        ans += cnt * (cnt - 1) // 2

# pprint(arr)
print(ans)
