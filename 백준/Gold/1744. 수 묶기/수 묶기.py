import sys
input = sys.stdin.readline

n = int(input())
pos = []
neg = []
zero = 0

for i in range(n):
    a = int(input())
    if a < 0: neg.append(a)
    elif a > 0: pos.append(a)
    else: zero += 1

pos.sort()
neg.sort(reverse=True)

ans = 0

while len(pos) > 1:
    if pos[-2] == 1: break
    ans += pos[-1] * pos[-2]
    pos.pop()
    pos.pop()

while len(neg) > 1:
    ans += neg[-1] * neg[-2]
    neg.pop()
    neg.pop()

ans += sum(pos)

if neg and zero == 0: ans += neg[0]

print(ans)


