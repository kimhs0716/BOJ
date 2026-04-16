import sys
input = lambda: sys.stdin.readline().rstrip()


try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass



check = set()
n = int(input())
ans = 0
for i in range(n):
    a, b, c = map(int, input().split())
    if a in check or b in check or c in check:
        pass
    else:
        ans += 1
    check.add(a)
    check.add(b)
    check.add(c)

print(ans)

