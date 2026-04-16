import sys
input = lambda: sys.stdin.readline().rstrip()

def swap(a, b):
    t = a[:]
    for i in range(len(a)):
        a[i] = b[i]
        b[i] = t[i]

class Matrix:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.arr = [ [0] * c for _ in range(r) ]
    
    def input(self, ss = ""):
        if not ss:
            ss = '\n'.join([ input() for _ in range(self.r) ])
        
        for idx, elem in enumerate(ss.split('\n')):
            self.arr[idx] = list(map(int, elem.split()))

    def __str__(self):
        ret = ''
        for i in range(self.r):
            ret += ' '.join(map(lambda x: str(round(x)), self.arr[i])) + '\n'
        return ret
    
    def interchange(self, r1, r2):
        swap(self.arr[r1], self.arr[r2])
    
    def scailing(self, r, s) :
        for i in range(self.c):
            self.arr[r][i] *= s
    
    def replace(self, src, dst, s):
        if s == 0: return
        self.scailing(src, s)
        for i in range(self.c):
            self.arr[dst][i] += self.arr[src][i]
        self.scailing(src, 1/s)
    
    def REF(self):
        for i in range(self.r):
            for j in range(i + 1, self.r):
                if self.arr[j][i] != 0:
                    swap(self.arr[i], self.arr[j])
                    break
            self.scailing(i, 1/self.arr[i][i])
            for j in range(self.r):
                if i == j: continue
                self.replace(i, j, -self.arr[j][i])

    def answer(self):
        self.REF()
        ret = []
        for i in range(self.r):
            ret.append(round(self.arr[i][r]))
        return ret

r = int(input())
m1 = Matrix(r, r + 1)
m1.input()
print(*m1.answer())

