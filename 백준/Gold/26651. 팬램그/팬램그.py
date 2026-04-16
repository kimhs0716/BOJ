def abc(a, n):
    t = n % 2
    k = a * 10 ** t
    i = int(k ** 0.5)
    while k % i: i += 1
    ans = [i, k // i]
    ans[0] *= 10 ** (n // 2)
    ans[1] *= 10 ** (n // 2)
    return 'A' * ans[0] + 'BCDEFGHIJKLMNOPQRSTUVWXY' + 'Z' * ans[1]
def solve(n):
    if n == 0: return 'FDZZ'
    if n == 1e9:
        return 'A' * 25000 + 'BCDEFGHIJKLMNOPQRSTUVWXY' + 'Z' * 40000
    ans = []
    i = 0
    while n:
        if n % 10: ans.append(abc(n % 10, i))
        i += 1
        n //= 10
    return ''.join(ans)
    
x = int(input())
s = solve(x)
print(s)
