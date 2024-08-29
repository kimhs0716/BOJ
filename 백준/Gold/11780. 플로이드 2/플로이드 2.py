import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


INF = 0x3f3f3f

class Graph:
    def __init__(self, n):
        self.n = n
        self.d = [[INF] * self.n for _ in range(self.n)]
        self.nxt = [[-1] * self.n for _ in range(self.n)]

    def add_edge(self, u, v, w):
        if self.d[u][v] > w:
            self.d[u][v] = w
        self.nxt[u][v] = v

    def floyd_warshall(self):
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    if j == k: continue
                    if self.d[j][k] > self.d[j][i] + self.d[i][k]:
                        self.d[j][k] = self.d[j][i] + self.d[i][k]
                        self.nxt[j][k] = self.nxt[j][i]


    def print(self):
        result = []
        for i in range(self.n):
            for j in range(self.n):
                if self.d[i][j] == INF: result.append('0')
                else: result.append(self.d[i][j])
                result.append(' ')
            result.append('\n')
        print(''.join(map(str, result[:-1])))

n = int(input())
m = int(input())

g = Graph(n)
for _ in range(m):
    u, v, w = map(int, input().split())
    g.add_edge(u - 1, v - 1, w)

g.floyd_warshall()
g.print()

for i in range(n):
    for j in range(n):
        if i == j: print(0)
        else:
            cur = i
            bt = [i + 1]
            while cur != j:
                cur = g.nxt[cur][j]
                if cur == -1: break
                bt.append(cur + 1)
            if cur != -1:
                print(len(bt), *bt)
            else:
                print(0)
