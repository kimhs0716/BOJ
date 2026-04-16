import sys
try:
    sys.stdin = open('./boj.in', 'r', encoding='utf-8')
except:
    input = lambda: sys.stdin.readline()[:-1]
    
class Matrix:
    def __init__(self):
        self.arr = [
            [0, 1], 
            [1, 1]
        ]
    
    def __mul__(self, m):
        ret = Matrix()
        ret.arr[0][0] = (self.arr[0][0] * m.arr[0][0] + self.arr[0][1] * m.arr[1][0]) % MOD
        ret.arr[0][1] = (self.arr[0][0] * m.arr[0][1] + self.arr[0][1] * m.arr[1][1]) % MOD
        ret.arr[1][0] = (self.arr[1][0] * m.arr[0][0] + self.arr[1][1] * m.arr[1][0]) % MOD
        ret.arr[1][1] = (self.arr[1][0] * m.arr[0][1] + self.arr[1][1] * m.arr[1][1]) % MOD
        return ret

def __pow(m, n):
    if n == 1: return m
    ret = __pow(m, n // 2)
    ret *= ret
    if n & 1: ret *= m
    return ret

MOD = int(1e9+7)

def fib(n):
    if n == 0: return 1
    m = __pow(Matrix(), n)
    return m.arr[0][1]

n = int(input())
print(fib(n), n - 2)

