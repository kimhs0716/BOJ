import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


r, c = map(int, input().split())
n = int(input())
heights = list(map(int, input().split()))

heights.sort(reverse=True)
ans = 0
arr = [float('inf')] * c
idx = 0
for i in heights:
    if i < arr[idx % c]:
        ans += 1
        arr[idx % c] = i
        idx += 1
        if idx == r * c: break

print(ans)
