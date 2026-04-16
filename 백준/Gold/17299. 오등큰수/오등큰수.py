import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
stack = []
ans = [0] * n

inp = list(map(int, input().split()))
c = dict(Counter(inp))

for i in range(n):
    cur = inp[i]
    while stack and c[stack[-1][0]] < c[cur]:
        ans[stack[-1][1]] = cur
        stack.pop()
    stack.append((cur, i))

result = []
for i in range(n):
    result.append(ans[i] if ans[i] else -1)
print(' '.join(map(str, result)))
