import sys
input = lambda: sys.stdin.readline().rstrip()


n, s = map(int, input().split())
arr = {int(input()) for _ in range(n)}

ans = 0
for i in arr:
    ans += (s-i in arr)
    if i<<1 == s: ans -= 1

print(ans>>1)
