a, b, c = map(int, input().split())
start = 11 * 24 * 60 + 11 * 60 + 11
end = a * 24 * 60 + b * 60 + c
if start > end: print(-1)
else: print(end - start)
