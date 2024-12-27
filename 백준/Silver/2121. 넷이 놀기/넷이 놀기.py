import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


def check(x, y):
    arr = [(x, y - h), (x + w, y), (x + w, y - h)] # upper left

    if all(map(lambda p: p in points, arr)): return True
    return False


n = int(input())
w, h = map(int, input().split())
points = set()

for i in range(n):
    x, y = map(int, input().split())
    points.add((x, y))

ans = 0
for p in points:
    ans += check(*p)

print(ans)
