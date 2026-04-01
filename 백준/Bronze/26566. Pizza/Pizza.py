import sys
input = lambda: sys.stdin.readline().rstrip()


pi = 3.1415926535
for _ in range(int(input())):
    a, p1 = map(int, input().split())
    r, p2 = map(int, input().split())
    if pi*r*r*p1 > a*p2:
        print("Whole pizza")
    else:
        print("Slice of pizza")

