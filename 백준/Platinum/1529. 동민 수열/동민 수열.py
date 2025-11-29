import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


MOD = 1_234_567_891

class Mat:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.arr = [[0] * c for _ in range(r)]

    def __getitem__(self, idx):
        return self.arr[idx]

    def __mul__(self, rhs):
        assert self.c == rhs.r
        ret = Mat(self.r, rhs.c)
        for i in range(self.r):
            for j in range(rhs.c):
                for k in range(self.c):
                    ret[i][j] += self[i][k] * rhs[k][j] % MOD
                    ret[i][j] %= MOD
        return ret

    def __str__(self):
        res = [' '.join(map(str, i)) for i in self.arr]
        return '\n'.join(res)


def I(n):
    ret = Mat(n, n)
    for i in range(n):
        ret[i][i] = 1
    return ret

def __pow(m, k):
    n = m.r
    ret = I(n)
    while k:
        if k&1: ret = ret * m
        m = m * m
        k >>= 1
    return ret

n, l = map(int, input().split())
arr = [i for i in input().split() if set(i).issubset(set('47')) ]
arr = list(set(arr))
n = len(arr)
f = Mat(n, n)
for i in range(n):
    for j in range(n):
        if arr[i][-1] == arr[j][0]:
            f[i][j] = 1

# print(arr)
# print(f)

f = __pow(f, l-1)
# print(f)

ans = 0
for i in range(n):
    for j in range(n):
        ans += f[i][j]
        ans %= MOD

print(ans)
