import sys
input = lambda: sys.stdin.readline().rstrip()


MAX = (1<<63)-1
def tree_hash(s, b, e):
    # print(s)
    ret = 0x123456789
    c = []
    l, r = b, b
    cnt = 0
    while l < e:
        if s[r]=='0': cnt += 1
        else: cnt -= 1
        if cnt==0:
            c.append((l, r+1))
            l = r+1
        r += 1
        if r==e:
            break
    # print(c)
    if len(c) == 1:
        return tree_hash(s, b+1, e-1)
    c = [tree_hash(s, *i) for i in c]
    c.sort()
    for i in range(len(c)):
        x = c[i]*((i<<3)^(i>>1)^0x123)
        ret ^= x<<13
        ret ^= x>>7
        ret ^= x<<5
    return ret & MAX


for _ in range(int(input())):
    s1 = input()
    s2 = input()
    h1 = tree_hash(s1, 0, len(s1))
    h2 = tree_hash(s2, 0, len(s2))
    print(int(h1==h2))
