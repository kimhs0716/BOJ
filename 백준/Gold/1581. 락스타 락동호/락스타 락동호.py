import sys
try:
    sys.stdin = open('./boj.in', 'r', encoding='utf-8')
except:
    input = lambda: sys.stdin.readline()[:-1]

ff, fs, sf, ss = map(int, input().split())

if (ff == 0 and fs == 0): # No Fast Starting Songs
    print(ss + (1 if sf else 0))
else:
    if fs == 0:
        print(ff)
    elif fs <= sf:
        print(ff + fs * 2 + ss)
    else:
        print(ff + sf * 2 + 1 + ss)
