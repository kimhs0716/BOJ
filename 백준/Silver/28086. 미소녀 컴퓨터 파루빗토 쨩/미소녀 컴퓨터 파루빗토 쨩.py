import sys
input = lambda: sys.stdin.readline().rstrip()


try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


def __oct(n):
    flag = n < 0
    n = abs(n)
    return '-' * flag + oct(n)[2:]

s = input()
if '+' in s: # A+B
    a, b = map(lambda x: int(x, 8), s.split('+'))
    print(__oct(a + b))
elif '*' in s: # A*B
    a, b = map(lambda x: int(x, 8), s.split('*'))
    print(__oct(a * b))
elif '/' in s: # A/B
    a, b = map(lambda x: int(x, 8), s.split('/'))
    if b == 0:
        print('invalid')
    else:
        print(__oct(a // b))
else: # A-B
    a, b = map(lambda x: int(x, 8), s.rsplit('-', 1))
    print(__oct(a - b))


