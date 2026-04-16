import sys
input = sys.stdin.readline

dr = [0, 1]
dc = [1, 0]

def dfs(arr, r, c):
    stack = []
    visited = set()
    stack.append((r, c))
    while stack:
        r, c = stack.pop()
        if r + 1 == len(arr) and c + 1 == len(arr[0]):
            return True
        for i in range(2):
            nr = r + arr[r][c] * dr[i]
            nc = c + arr[r][c] * dc[i]
            if nr < len(arr) and nc < len(arr[0]):
                if (nr, nc) in visited: continue
                visited.add((nr, nc))
                stack.append((nr, nc))
    return False

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
print(["Hing", "HaruHaru"][dfs(arr, 0, 0)])