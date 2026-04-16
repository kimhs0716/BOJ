n = int(input())
arr = list(map(int, input().split()))

x = 0
for i in arr:
    x ^= i

if arr[0] == 1 and len(set(arr)) == 1:
    x ^= 1

print('koosaga' if x else 'cubelover')


"""
import random


def mex(s):
    i = 0
    while i in s:
        i += 1
    return i


cache = {(1,): 0, (0, ): 1}
def gn(*args):
    k = tuple(sorted(args))
    if k in cache: return cache[k]
    if k[0] == 0:
        cache[k] = gn(*k[1:])
        return cache[k]
    s = set()
    for i in range(len(k)):
        t = list(k)
        for j in range(t[i]):
            t[i] -= 1
            s.add(gn(*t))
    cache[k] = mex(s)
    return cache[k]

def g(*args):
    s = 0
    for i in args:
        s ^= i
    return s


for i in range(30):
    k = random.randint(1, 5)
    arr = [random.randint(1, 2) for _ in range(k)]
    print(gn(*arr) == g(*arr), gn(*arr), g(*arr), arr)

"""