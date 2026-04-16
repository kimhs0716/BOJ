import sys
input = lambda: sys.stdin.readline()[:-1]

from collections import deque

n, m = map(int, input().split())
s = int(input())

money = deque()
form = set()
ans = []

for _ in range(m):
    # print(form, money)
    i, t = map(int, input().split())
    if t == 0:
        form.add(i)
        for i in range(len(money)):
            money[i][0] += 1
        while money and money[0][0] >= s:
            i = money.popleft()[1]
            if i not in form:
                ans.append(i)
    else:
        money.append([0, i])

if ans:
    print(*sorted(ans))
else:
    print(-1)
