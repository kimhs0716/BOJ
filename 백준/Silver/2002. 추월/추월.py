import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
d = {}
ans = 0

for i in range(n):
    s = input()
    d[s] = i

found = set()
for i in range(n):
    s = input()
    # print(set(range(d[s])), found)
    if (set(range(d[s])) - found): ans += 1
    found.add(d[s])

print(ans)
