from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    node = ['1', 1 % n]
    q = deque()
    q.append(node)
    visited = [0] * n
    visited[node[1]] = 1
    while q:
        node = q.popleft()
        if node[1] == 0:
            print(node[0])
            break
        new_node = [node[0] + '0', node[1] * 10 % n]
        if visited[new_node[1]] == 0:
            visited[new_node[1]] = 1
            q.append(new_node)
        new_node = [node[0] + '1', (node[1] * 10 + 1) % n]
        if visited[new_node[1]] == 0:
            visited[new_node[1]] = 1
            q.append(new_node)
    else:
        print('BRAK')
