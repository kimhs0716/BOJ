import sys
input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
neg, pos = [], []

for _ in range(n):
    num = int(input())
    if num < 0:
        neg.append(-num)
    else:
        pos.append(num)

neg.sort()
pos.sort()
ans = 0

while True:
    if pos: ans += pos[-1] * 2
    for _ in range(k):
        if pos: pos.pop()

    if neg: ans += neg[-1] * 2
    for _ in range(k):
        if neg: neg.pop()

    if not pos and not neg: break

print(ans)

