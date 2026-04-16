def sqrt(n):
    return int(n ** 0.5)


def solve(n):
    flag = n < 0
    n = abs(n)

    if n == 0:
        return flag, [3, 4, -5]
    if n == 2:
        return flag, [-3, -5, 6]

    sq = sqrt(n)
    if sq ** 2 == n:
        return flag, [sq]

    i = 1
    while 2 * i * i < n:
        c = n - i * i
        s = sqrt(c)
        if s * s == c:
            return flag, [i, s]
        i += 1

    c = 1
    while c * c < n:
        if n % c == 0:
            d = n // c
            if (c + d) % 2 == 0:
                a = (c + d) // 2
                b = (d - c) // 2
                return flag, [a, -b]
        c += 1

    m = (n - 2) // 4
    return flag, [1, 2 * m + 1, -(2 * m)]


n = int(input())
f, arr = solve(n)

if f == -1:
    print(-1)
else:
    check = 0
    assert len(arr) == len(set(map(abs, arr)))
    print(len(arr))
    for i in arr:
        if f:
            i = -i
        assert i != 0
        if i < 0:
            print('-', -i)
            check -= i * i
        else:
            print('+', i)
            check += i * i

    assert check == n
