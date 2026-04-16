import sys
input = lambda: sys.stdin.readline()[:-1]

price = dict()

b, n, m = map(int, input().split())
for i in range(n):
    name, p = input().split()
    price[name] = int(p)

if b >= sum(map(price.get, [input() for _ in range(m)])):
    print("acceptable")
else:
    print("unacceptable")
