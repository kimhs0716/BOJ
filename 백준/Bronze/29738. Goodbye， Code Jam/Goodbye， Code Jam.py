for x in range(1, int(input()) + 1):
    n = int(input())
    print(f'Case #{x}: ', end='')
    if n > 4500:
        print('Round 1')
    elif n > 1000:
        print('Round 2')
    elif n > 25:
        print('Round 3')
    else:
        print('World Finals')
