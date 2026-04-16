a, b, h = map(int, input().split())
PI = 3.1415926535897932384626

if a == b: print(-1)
else:
    if a > b: a, b = b, a
    if a == 0:
        x = 0
        y = (h * h + b * b) ** 0.5
    else:
        x = ((h * h + (b - a) ** 2) ** 0.5) * a / (b - a)
        y = x * b / a
    print(PI * (y * y - x * x))