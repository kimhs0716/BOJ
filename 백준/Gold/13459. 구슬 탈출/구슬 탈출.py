from collections import deque

def left(arr, red, blue):
    while arr[red[0]][red[1] - 1] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0], red[1] - 1)
        arr[red[0]][red[1]] = 'R'
    if arr[red[0]][red[1] - 1] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)
    
    while arr[blue[0]][blue[1] - 1] =='.':
        arr[blue[0]][blue[1]] = '.'
        blue = (blue[0], blue[1] - 1)
        arr[blue[0]][blue[1]] = 'B'
    if arr[blue[0]][blue[1] - 1] == 'O':
        arr[blue[0]][blue[1]] = '.'
        blue = (-1, -1)
    
    while arr[red[0]][red[1] - 1] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0], red[1] - 1)
        arr[red[0]][red[1]] = 'R'
    if arr[red[0]][red[1] - 1] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    return (red, blue, arr)

def right(arr, red, blue):
    while arr[red[0]][red[1] + 1] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0], red[1] + 1)
        arr[red[0]][red[1]] = 'R'
    if arr[red[0]][red[1] + 1] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)
    
    while arr[blue[0]][blue[1] + 1] =='.':
        arr[blue[0]][blue[1]] = '.'
        blue = (blue[0], blue[1] + 1)
        arr[blue[0]][blue[1]] = 'B'
    if arr[blue[0]][blue[1] + 1] == 'O':
        arr[blue[0]][blue[1]] = '.'
        blue = (-1, -1)
    
    while arr[red[0]][red[1] + 1] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0], red[1] + 1)
        arr[red[0]][red[1]] = 'R'
    if arr[red[0]][red[1] + 1] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    return (red, blue, arr)

def up(arr, red, blue):
    while arr[red[0] - 1][red[1]] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0] - 1, red[1])
        arr[red[0]][red[1]] = 'R'
    if arr[red[0] - 1][red[1]] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    while arr[blue[0] - 1][blue[1]] =='.':
        arr[blue[0]][blue[1]] = '.'
        blue = (blue[0] - 1, blue[1])
        arr[blue[0]][blue[1]] = 'B'
    if arr[blue[0] - 1][blue[1]] == 'O':
        arr[blue[0]][blue[1]] = '.'
        blue = (-1, -1)
    
    while arr[red[0] - 1][red[1]] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0] - 1, red[1])
        arr[red[0]][red[1]] = 'R'
    if arr[red[0] - 1][red[1]] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    return (red, blue, arr)

def down(arr, red, blue):
    while arr[red[0] + 1][red[1]] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0] + 1, red[1])
        arr[red[0]][red[1]] = 'R'
    if arr[red[0] + 1][red[1]] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    while arr[blue[0] + 1][blue[1]] =='.':
        arr[blue[0]][blue[1]] = '.'
        blue = (blue[0] + 1, blue[1])
        arr[blue[0]][blue[1]] = 'B'
    if arr[blue[0] + 1][blue[1]] == 'O':
        arr[blue[0]][blue[1]] = '.'
        blue = (-1, -1)
    
    while arr[red[0] + 1][red[1]] =='.':
        arr[red[0]][red[1]] = '.'
        red = (red[0] + 1, red[1])
        arr[red[0]][red[1]] = 'R'
    if arr[red[0] + 1][red[1]] == 'O':
        arr[red[0]][red[1]] = '.'
        red = (-1, -1)

    return (red, blue, arr)
    
r, c = map(int, input().split())
arr = [list(input()) for _ in range(r)]
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'R':
            red = (i, j)
        if arr[i][j] == 'B':
            blue = (i, j)

def pprint(arr):
    for i in arr:
        print(''.join(i))
    print()

visited = {}
first = (red, blue)
visited[first] = 1
q = deque()
q.append((first, 0, [i[:] for i in arr]))
flag = True
while True:
    if not q:
        flag = False
        break
    p = q.popleft()
    # print(p[:2])
    # pprint([i[:] for i in p[2]])
    if p[1] == 11:
        flag = False
        break
    if p[0][0] == (-1, -1) and p[0][1] != (-1, -1):
        flag = True
        break
        
    l = left([i[:] for i in p[2]], *p[0])
    if l[:2] not in visited:
        visited[l[:2]] = True
        q.append((l[:2], p[1] + 1, l[2]))
        
    l = up([i[:] for i in p[2]], *p[0])
    if l[:2] not in visited:
        visited[l[:2]] = True
        q.append((l[:2], p[1] + 1, l[2]))
        
    l = right([i[:] for i in p[2]], *p[0])
    if l[:2] not in visited:
        visited[l[:2]] = True
        q.append((l[:2], p[1] + 1, l[2]))
        
    l = down([i[:] for i in p[2]], *p[0])
    if l[:2] not in visited:
        visited[l[:2]] = True
        q.append((l[:2], p[1] + 1, l[2]))

print(int(flag))