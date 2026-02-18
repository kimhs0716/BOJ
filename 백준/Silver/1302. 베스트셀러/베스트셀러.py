import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
cnt = dict()
ans = None
for _ in range(n):
    s = input()
    cnt[s] = cnt.get(s, 0) + 1
    ans = min((ans, s), key=lambda x: (-cnt[x], x)) if ans else s
print(ans)
