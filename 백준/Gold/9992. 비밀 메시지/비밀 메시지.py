import sys
input = lambda: sys.stdin.readline()[:-1]


from functools import cache


@cache
def f(s):
    ret = 1
    n = len(s)
    for i in range(1, (n+1)//2):
        x = s[:i]
        if s[i:].startswith(x):
            ret = (ret+f(s[i:])) % 2014
        if s[i:].endswith(x):
            ret = (ret+f(s[i:])) % 2014
        x = s[-i:]
        if s[:-i].startswith(x):
            ret = (ret+f(s[:-i])) % 2014
        if s[:-i].endswith(x):
            ret = (ret+f(s[:-i])) % 2014
    # print(s, ret)
    return ret

s = input()
print(f(s)-1)
