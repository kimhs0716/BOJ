def solve(p, q):
    if p == 1 and q == 1: return 1
    if p > q:
        return 2 * solve(p - q, q) + 1
    return 2 * solve(p, q - p)

for p in range(1, int(input()) + 1):
    k, s = input().split()
    p, q = map(int, s.split('/'))
    print(k, solve(p, q))
