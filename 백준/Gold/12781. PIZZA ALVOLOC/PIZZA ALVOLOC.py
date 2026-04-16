def cross(a, b, c):
    return (a[0] * b[1] + b[0] * c[1] + c[0] * a[1]) - \
           (b[0] * a[1] + c[0] * b[1] + a[0] * c[1])

arr = tuple(map(int, input().split()))
a, b, c, d = arr[:2], arr[2:4], arr[4:6], arr[6:]

if a[0] == b[0]:
    if c[0] == d[0]:
        print(0)
        exit(0)
    e = (a[0], (c[1] - d[1]) / (c[0] - d[0]) * (a[0] - c[0]) + c[1])
else:
    if c[0] == d[0]:
        e = (c[0], (a[1] - b[1]) / (a[0] - b[0]) * (c[0] - a[0]) + a[1])
    else:
        t1 = (a[1] - b[1]) / (a[0] - b[0])
        t2 = (c[1] - d[1]) / (c[0] - d[0])
        if t1 == t2:
            print(0)
            exit(0)
        x = (t1 * a[0] - t2 * c[0] + c[1] - a[1]) / (t1 - t2)
        e = (x, t1 * (x - a[0]) + a[1])
print(int(cross(a, e, c) * cross(a, e, d) < 0))
