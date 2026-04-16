n, k = map(int, input().split())
arr = [*map(int, input().split())]
sarr = []
s = 0

for i in arr:
    s += i
    sarr.append(s)

print(sum(sorted(sarr, reverse=True)[:k]))
