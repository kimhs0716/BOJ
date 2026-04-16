a, b = map(int, input().split())
ans = 0

def gen():
    i = 1
    j = 1
    while True:
        for _ in range(j):
            yield (j, i)
            i += 1
        j += 1

for i, idx in gen():
    if a <= idx <= b:
        ans += i
    if idx > b: break

print(ans)
