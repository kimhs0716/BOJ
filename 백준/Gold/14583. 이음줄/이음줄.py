w, h = map(float, input().split())
a = (h * h + w * w) ** 0.5
x = h * w / (w + a)
S = w * (h - x)
v = (w * w + x * x) ** 0.5

print('%.2f %.2f' % (v / 2, S / v))
