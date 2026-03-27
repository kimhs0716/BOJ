import sys
input = lambda: sys.stdin.readline().rstrip()


n, k = map(int, input().split())
tar = []
for i in range(1, k+1):
    t = k//i
    if t<=i:
        if t==i: tar.append(t)
        break
    tar += [i, t]

tar.sort()
# print(tar)

cur = n
d = 0
while tar[-1] > cur:
    tar.pop()
    d += 1
    
# print(d, tar)
ans = 0
# print(ans)
while tar:
    lo = k%cur
    l = cur-tar[-1]
    # print(cur, tar[-1], lo, l, lo+d*(l-1), lo*l + d*(l-1)*l//2)
    ans += lo*l + d*(l-1)*l//2
    cur = tar[-1]
    tar.pop()
    d += 1

print(ans)

"""
naive = 0
for i in range(1, n+1):
    naive += k%i
    # print(i, k%i)
print(naive)
"""
