import sys, decimal
input = lambda: sys.stdin.readline().rstrip()

tc = int(input())

for _ in range(tc):
    n, m = map(decimal.Decimal, '0 1e18'.split())
    while True:
        mid = (n + m) / 2
        c = int((mid - n).sqrt())
        # print(n, m, mid, c)
        print(f'? {n} {c}')
        sys.stdout.flush()
        ans = input()
        if ans == '!':
            assert False
        elif ans == '+':
            n = c ** 2 + n + 1
        elif ans == '-':
            m = c ** 2 + n - 1
        else:
            print(f'! {n + c ** 2}')
            sys.stdout.flush()
            break