import sys
input = sys.stdin.readline

n = int(input())
x, y = map(int, input().split())
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 <= x <= x2 and y1 <= y <= y2:
        print("Yes")
        break
else:
    print("No")
