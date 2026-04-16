import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = map(int, input().split())

v = 0
m = 0
for x in arr:
    m = max(m, x)
    v += m
print("Oh My God!" if v%3 else "Delicious!")
