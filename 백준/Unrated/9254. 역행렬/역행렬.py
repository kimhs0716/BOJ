import sys
input = lambda: sys.stdin.readline().rstrip()


eps = 1e-10
def is_zero(x):
    return abs(x) < eps

def gauss_jordan(a):
    n = len(a)
    a = [row[:] for row in a]
    irow = [0]*n
    icol = [0]*n
    ipiv = [0]*n
    for i in range(n):
        pj = -1
        pk = -1
        for j in range(n):
            if not ipiv[j]:
                for k in range(n):
                    if not ipiv[k]:
                        if pj<0 or abs(a[j][k]) > abs(a[pj][pk]):
                            pj = j
                            pk = k
        if is_zero(a[pj][pk]): return None
        ipiv[pk] += 1
        a[pj], a[pk] = a[pk], a[pj]
        irow[i] = pj
        icol[i] = pk
        c = 1 / a[pk][pk]
        a[pk][pk] = 1
        for p in range(n): a[pk][p] *= c
        for p in range(n):
            if p!=pk:
                c = a[p][pk]
                a[p][pk] = 0
                for q in range(n):
                    a[p][q] -= a[pk][q]*c
    for p in range(n-1, -1, -1):
        if irow[p]!=icol[p]:
            for k in range(n):
                a[k][irow[p]], a[k][icol[p]] = a[k][icol[p]], a[k][irow[p]]
    return a

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
inv = gauss_jordan(a)
if inv:
    for i in inv:
        print(*i)
else:
    print("no inverse")
