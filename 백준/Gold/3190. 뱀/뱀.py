import sys
from collections import deque

input = lambda: sys.stdin.readline()[:-1]

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

n = int(input())
k = int(input())
apples = set()
for i in range(k):
    r, c = map(int, input().split())
    apples.add((r - 1, c - 1))
l = int(input())
cmd = []
for i in range(l):
    t, c = input().split()
    cmd.append([int(t), c])
time = 0

snake = deque()
snake.append((0, 0))
direction = 0  # right
r, c = 0, 0
idx = 0

while True:
    flag = True
    time += 1
    r, c = snake[-1]
    nr, nc = r + dr[direction], c + dc[direction]
    if nr < 0 or nr >= n or nc < 0 or nc >= n:
        flag = False
    for b in snake:
        if (nr, nc) == b:
            flag = False
            break
    if not flag: break

    if (nr, nc) in apples:
        apples.remove((nr, nc))
        snake.appendleft(snake[0])

    snake.append((nr, nc))
    snake.popleft()

    if idx < l and cmd[idx][0] == time:
        if cmd[idx][1] == 'L': direction = (direction - 1) % 4
        else: direction = (direction + 1) % 4
        idx += 1

    '''
    # print(time, direction, snake)
    print("=======================")
    print(time, cmd[idx])
    for i in range(n):
        for j in range(n):
            if (i, j) in apples: print("A", end="")
            elif (i, j) == snake[-1]: print("H", end="")
            elif (i, j) in snake: print("O", end="")
            else: print(".", end="")
        print()
    input()
    '''

print(time)