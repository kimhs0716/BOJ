import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

ans = [0, 0, 0, 0]
n = int(input())
for _ in range(n - 2):
    a = list(map(int, input())).index(0)
    for i in range(4):
        if a == i: continue
        if abs(a - i) % 2: ans[i] += 1
        else: ans[i] += 2
    # print(ans)
print(min(ans) + n + 2)
