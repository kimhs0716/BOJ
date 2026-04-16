import sys
input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
arr = [0] * n

for i in range(m):
    cmd = [*map(int, input().split())]
    if cmd[0] == 1:
        arr[cmd[1] - 1] |= (1 << (cmd[2] - 1))
    elif cmd[0] == 2:
        arr[cmd[1] - 1] &= ~(1 << (cmd[2] - 1))
    elif cmd[0] == 4:
        arr[cmd[1] - 1] >>= 1
    else:
        arr[cmd[1] - 1] <<= 1
        arr[cmd[1] - 1] &= ~(1 << 20)

cnt = 0
visited = set()
for i in arr:
    if i not in visited:
        visited.add(i)
        cnt += 1
print(cnt)
