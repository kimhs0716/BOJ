import sys
input = lambda: sys.stdin.readline()[:-1]

def rgb2hsv(r, g, b):
    v = max((r, g, b))
    m = min((r, g, b))
    s = 255 * (v - m) / v
    if v == r:
        h = 60 * (g - b) / (v - m)
    elif v == g:
        h = 120 + 60 * (b - r) / (v - m)
    else:
        h = 240 + 60 * (r - g) / (v - m)
    if h < 0: h += 360

    return h, s, v

hl, hh = map(int, input().split())
sl, sh = map(int, input().split())
vl, vh = map(int, input().split())
r, g, b = map(int, input().split())

h, s, v = rgb2hsv(r, g, b)

if hl <= h <= hh and sl <= s <= sh and vl <= v <= vh:
    print("Lumi will like it.")
else:
    print("Lumi will not like it.")
