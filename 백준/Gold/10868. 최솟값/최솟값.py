import sys

try:
    sys.stdin = open("boj.in", "r", encoding="utf-8")
    sys.stdout = open("boj.out", "w", encoding="utf-8")
except:
    pass

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

INF = float('inf')


class SEG:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.seg = [0] * (self.n<<2)
        self.init(1, 0, self.n-1)

    def init(self, i, l, r):
        if l==r:
            self.seg[i] = l
            return
        m = l+r>>1
        self.init(i<<1, l, m)
        self.init(i<<1|1, m+1, r)
        li = self.seg[i<<1]
        ri = self.seg[i<<1|1]
        if self.arr[ri] < self.arr[li]:
            self.seg[i] = ri
        else:
            self.seg[i] = li

    def range_query(self, i, l, r, s, e):
        if s<=l and r<=e: return self.seg[i]
        if e<l or r<s: return -1
        m = l+r>>1
        li = self.range_query(i<<1, l, m, s, e)
        ri = self.range_query(i<<1|1, m+1, r, s, e)
        if li == -1:
            if ri == -1: return -1
            return ri
        if ri == -1: return li
        if self.arr[ri] < self.arr[li]:
            return ri
        return li

    def query(self, s, e):
        return self.range_query(1, 0, self.n-1, s, e)

def preprocess():
    pass

def solve(tc):
    n, q = map(int, input().split())
    arr = [int(input()) for _ in range(n)]
    seg = SEG(arr)
    for _ in range(q):
        a, b = map(int, input().split())
        print(arr[seg.query(a-1, b-1)])


def main():
    preprocess()
    tc = 1
    # tc = int(input())
    for _ in range(tc):
        solve(_+1)

if __name__ == "__main__":
    main()