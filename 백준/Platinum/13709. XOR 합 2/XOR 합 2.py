import sys
input = lambda: sys.stdin.readline().rstrip()


class GF2:
    def __init__(self):
        self.basis = set()

    def add(self, x):
        for b in self.basis:
            for i in range(63, -1, -1):
                if (b>>i)&1: break
            if ((b>>i)&1) and ((x>>i)&1):
                x ^= b
        if x: self.basis.add(x)

    def get(self):
        ret = 0
        for b in sorted(self.basis, reverse=True):
            if (ret^b) > ret:
                ret ^= b
        return ret


n = int(input())
gf2 = GF2()
for x in map(int, input().split()):
    gf2.add(x)
print(gf2.get())
