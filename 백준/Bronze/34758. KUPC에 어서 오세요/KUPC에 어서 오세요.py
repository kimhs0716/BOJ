x, y = map(int, input().split())
for _ in range(int(input())):
    xx, yy = map(int, input().split())
    if x==xx or y==yy: print(0)
    else: print(1)
    