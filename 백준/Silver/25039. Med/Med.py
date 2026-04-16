n = int(input())
arr = []
order = dict()
s = dict()
for i in range(n):
    name, *scores = input().split()
    score = sum(map(int, scores))
    arr.append([score, name])
    order[name] = i
    s[name] = score
ans = []
for score, name in arr:
    t = [0, 0]
    s[name] += 500
    t[0] = n - sorted(arr, key=lambda x: (-s[x[1]], x[1]), reverse=True).index([score, name])
    s[name] -= 1000
    t[1] = n - sorted(arr, key=lambda x: (-s[x[1]], x[1]), reverse=True).index([score, name])
    s[name] += 500
    ans.append(t)
for i in ans:
    print(*i)
    