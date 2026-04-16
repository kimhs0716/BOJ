a = input()
if '0' in a and sum(map(int, a)) % 3 == 0:
    print(''.join(sorted(a, reverse=True)))
else:
    print(-1)
