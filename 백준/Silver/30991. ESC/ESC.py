class Matrix:
    def __init__(self, r, c, arr = []):
        self.r = r
        self.c = c
        self.arr = [[0] * c for _ in range(r)]
        if arr: self.arr = arr
    
    def __mul__(self, m):
        if self.c != m.r: raise 'ERROR!!!'
        ret = Matrix(self.r, m.c)
        for i in range(self.r):
            for j in range(m.c):
                s = 0
                for k in range(self.c): s += self.arr[i][k] * m.arr[k][j]
                ret.arr[i][j] = s
        return ret

n = int(input())
esc = Matrix(1, 3, [[1, 0, 0]])
M = Matrix(3, 3, [
    [1, 1, -1],
    [-2, 1, 0],
    [2, 0, 1]
])

for i in range(n):
    esc *= M

print(sum(esc.arr[0]))