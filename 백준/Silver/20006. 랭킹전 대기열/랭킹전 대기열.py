import sys
input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
level = dict()
rooms = []
for _ in range(n):
    l, name = input().split()
    l = int(l)
    level[name] = l
    for i in range(len(rooms)):
        if len(rooms[i]) == m:
            continue
        c = level[rooms[i][0]]
        if c-10 <= l <= c+10:
            rooms[i].append(name)
            break
    else:
        rooms.append([name])

for room in rooms:
    if len(room) == m:
        print("Started!")
    else:
        print("Waiting!")
    for p in sorted(room):
        print(level[p], p)
