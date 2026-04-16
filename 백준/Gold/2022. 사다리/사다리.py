diff = 3e-4

x, y, c = map(float, input().split())

m, M = 0, min(x, y)

def solve(w):
    X = x ** 2 - w ** 2
    Y = y ** 2 - w ** 2
    t =  X * Y - c ** 2 * (X + Y + 2 * (X * Y) ** 0.5)
    return t

while True:
    mid = (m + M) / 2
    t = solve(mid)
    # print(t, m, M)

    if t >= 0 and solve(mid + diff) <= 0:
        print('%.3f' % (mid + diff))
        break
    
    if t > 0:
        m = mid
    else:
        M = mid
