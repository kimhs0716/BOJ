n = int(input())
if n == 0:
    print('NO')
    exit(0)
while n != 1:
    if n % 3 == 2:
        print('NO')
        break
    n //= 3
else:
    print('YES')
