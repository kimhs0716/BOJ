s = input()
t = input()

ss = set(s)
tt = set(t)
assert len(ss - set('AB')) == 0 and len(tt - set('AB')) == 0

while s != t:
    if len(t) == 0:
        print(0)
        exit(0)
    if t[-1] == 'A':
        t = t[:-1]
    elif t[-1] == 'B':
        t = t[:-1][::-1]
    else:
        print(0)
        exit(0)
print(1)
