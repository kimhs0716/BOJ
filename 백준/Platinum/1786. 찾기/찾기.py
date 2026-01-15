import sys
input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9+7
INF = float('inf')

sys.setrecursionlimit(10**5+1000)


def get_pi(p):
    m = len(p)
    pi = [0]*m
    j = 0
    for i in range(1, m):
        while j>0 and p[i]!=p[j]:
            j = pi[j-1]
        if p[i]==p[j]:
            pi[i] = j+1
            j += 1
    return pi

def kmp(t, p):
    ret = []
    pi = get_pi(p)
    n = len(t)
    m = len(p)
    j = 0
    for i in range(n):
        while j>0 and t[i]!=p[j]:
            j = pi[j-1]
        if t[i]==p[j]:
            if j==m-1:
                ret.append(i-j)
                j = pi[j]
            else:
                j += 1
    return ret

t = input()
p = input()
res = kmp(t, p)
print(len(res))
for i in res:
    print(i+1, end=' ')
    