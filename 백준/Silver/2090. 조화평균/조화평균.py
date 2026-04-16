class Fraction:
    def __init__(self, ja, mo = 1):
        self.ja = ja
        self.mo = mo

    def __add__(self, f):
        if isinstance(f, int):
            f = Fraction(f)
        #print(self, f)
        return simplified(Fraction(self.ja * f.mo + self.mo * f.ja, self.mo * f.mo))

    def __radd__(self, f):
        return self + f

    def __sim__(self):
        from math import gcd
        g = gcd(self.ja, self.mo)
        return Fraction(self.ja // g, self.mo // g)

    def __inv__(self):
        return Fraction(self.mo, self.ja)

    def __str__(self):
        return f'{self.ja}/{self.mo}'

    def __repr__(self):
        return str(self)

def simplified(f):
    return f.__sim__()

def inv(f):
    return f.__inv__()

def solve(n):
    return inv(Fraction(int(n)))

input()
print(inv(sum(map(solve, input().split()))))
