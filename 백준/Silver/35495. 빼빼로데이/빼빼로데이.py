import sys
input = lambda: sys.stdin.readline().rstrip()


def days(y, m):
    if m in (1, 3, 5, 7, 8, 10, 12): return 31
    elif m==2:
        if y%4 or (y%100==0 and y%400): return 28
        return 29
    return 30

t = int(input())
a, b, c = map(int, input().split())
ans = 0
y, m, d = 2023, 1, 1

while True:
    cnt = str(y).count('1')
    cnt += str(m).count('1')
    cnt += str(d).count('1')
    if cnt >= t: ans += 1
    if (y, m, d) == (a, b, c): break
    d += 1
    if days(y, m) < d:
        d = 1
        m += 1
    if m==13:
        y += 1
        m = 1
    # print(y, m, d, cnt)
print(ans)
