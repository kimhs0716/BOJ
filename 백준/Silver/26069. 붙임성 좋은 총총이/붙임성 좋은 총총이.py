dance = set(('ChongChong', ))
for _ in range(int(input())):
    a, b = input().split()
    if a in dance or b in dance:
        dance |= set((a, b))
print(len(dance))
