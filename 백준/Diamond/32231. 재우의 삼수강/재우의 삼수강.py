from math import log
for _ in range(int(input())):
    _, a, _, b = map(int, input().split())
    print(abs(log(a) - log(b)))