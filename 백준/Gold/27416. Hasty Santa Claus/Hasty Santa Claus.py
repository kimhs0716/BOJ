import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n, k = map(int, input().split())
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append([a, b, i])
arr.sort(key=lambda x: (x[0], x[1]))

# print(*arr, sep='\n')

ans = dict()
idx = 0
t = 1
while idx < n:
    c = 0
    while c < k and arr:
        arr.sort(key=lambda x: (x[0] > t, x[1]))
        if arr[0][0] > t: break
        ans[arr[0][2]] = t
        del arr[0]
        c += 1
    t += 1
    if t >= 32: break
    # print(arr)

for i in range(n):
    print(ans[i])
