import sys
input = lambda: sys.stdin.readline().rstrip()

import string

def int2str(n):
    base = 26
    ret = ''
    if n == 0: ret = '0'
    else:
        while n:
            r = n % base
            r = string.ascii_lowercase[r]
            ret += r
            n //= base
        ret = ret[::-1]
    return ret.zfill(13).replace('0', 'a')

def str2int(s):
    ret = 0
    base = 26
    for c in s:
        ret *= base
        ret += string.ascii_lowercase.index(c)
    return ret


t = int(input())
if t == 1:
    s = sum(map(int, input().split()))
    print(int2str(s))
else:
    print(str2int(input()))
