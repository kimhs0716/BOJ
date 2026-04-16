import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


# 별해 (솔브닥의 난이도 의견 중에서 힌트를 얻어 해결)
# 123^400=1이므로, 123^(1+800)=123이다. 따라서 x는 123^(801/3) (mod 1000)

# S는 10**n과 서로소이므로
# S^phi(10**n)=1 (mod 10**n) 이다. (오일러 정리)
# phi(10**n) = 4 * (10**(n-1)) 이므로
# x = S^((phi(10**n) * 2 + 1) / 3) (mod 10**n) 이다

def __pow(n, r, m):
    if r == 0: return 1
    ret = __pow(n, r >> 1, m)
    ret = (ret * ret) % m
    if r & 1:
        ret = (ret * n) % m
    return ret

def solve(s, l):
    phi = 4 * (10 ** (l - 1))
    return __pow(s, (2 * phi + 1) // 3, 10 ** l)



for _ in range(int(input())):
    s = int(input())
    print(solve(s, len(str(s))))
