import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

def divs(n):
    s = set()
    for i in range(1, int(n ** 0.5) + 2):
        if n % i == 0:
            s.add(i)
            s.add(n // i)
    s -= {0, n}
    return sorted(s)

print(*divs(int(input()) + 1))
