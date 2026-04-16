class Matrix:
    mod = 1000000000
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.arr = [ [0] * c for _ in range(r) ]
    
    def input(self, string=''):
        if not string:
            for i in range(self.r):
                self.arr[i] = [ *map(int, input().split()) ]
        else:
            sstream = map(int, string.split())
            for i in range(self.r):
                for j in range(self.c):
                    self.arr[i][j] = next(sstream)

    def print(self):
        for i in range(self.r):
            for j in range(self.c):
                print(self.arr[i][j], end=' ')
            print()

    def __mul__(self, m):
        if self.c != m.r: raise "size not responding"
        ret = Matrix(self.r, m.c)
        for i in range(self.r):
            for j in range(m.c):
                for k in range(self.c):
                    ret.arr[i][j] += self.arr[i][k] * m.arr[k][j]
                    ret.arr[i][j] %= Matrix.mod
        return ret
    
    def __pow__(self, n):
        if n == 1: return self
        ret = Matrix.__pow__(self, n >> 1)
        ret = ret * ret
        if n & 1: ret = ret * self
        return ret

a, b, m = map(int, input().split())
Matrix.mod = m

r = Matrix(2, 2)
r.input(f'0 1 -1 {a}')

f = Matrix(2, 1)
f.input(f'2 {a}')

print((r ** b * f).arr[0][0]) 


