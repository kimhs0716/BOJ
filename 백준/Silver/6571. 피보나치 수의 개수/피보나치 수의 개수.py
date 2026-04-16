while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    cnt = 0
    c, d = 1, 2
    while c < a: c, d = d, c + d
    while c <= b:
        cnt += 1
        c, d = d, c + d
    print(cnt)
