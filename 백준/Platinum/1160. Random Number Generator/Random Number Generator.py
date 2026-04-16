class Matrix:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.arr = [[0] * c for _ in range(r)]

    def __mul__(self, m):
        global mod
        if self.c != m.r:
            raise Exception("Multiplying Invalid Matrix Size")
        ret = Matrix(self.r, m.c)
        for i in range(self.r):
            for j in range(m.c):
                s = 0
                for k in range(self.c):
                    s += self.arr[i][k] * m.arr[k][j] % mod
                    s %= mod
                ret.arr[i][j] = s
        return ret

def I(n):
    ret = Matrix(n, n)
    for i in range(n):
        ret.arr[i][i] = 1
    return ret

def __pow(m, r):
    if r == 0:
        return I(m.r)
    ret = __pow(m, r // 2)
    ret = ret * ret
    if r & 1: ret = ret * m
    return ret

mod, a, c, x0, n, g = map(int, input().split())
x1 = (a * x0 + c) % mod
m1 = Matrix(3, 3)
f = Matrix(3, 1)
m1.arr = [
    [0, 0, 0],
    [1, 0, 0],
    [0, 0, 1]
]
m1.arr[0][0] = a
m1.arr[0][2] = c

f.arr = [[x1], [x0], [1]]

print((__pow(m1, n) * f).arr[1][0] % g)
