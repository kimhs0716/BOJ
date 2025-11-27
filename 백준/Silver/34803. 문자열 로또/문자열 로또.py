l, n = map(int, input().split())
arr = [input() for _ in range(n)]
k = int(input())

cnt = dict()
for s in arr:
    for i in range(len(s)-k+1):
        cnt[s[i:i+k]] = cnt.get(s[i:i+k], 0) + 1

print(max(cnt.values()))
