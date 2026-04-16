import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
arr = [0] * 1002
s = 0

for i in range(n):
    d, c = input().split()
    c = int(c)

    if d == 'jinju':
        jinju = c
    
    else:
        if c > 1000:
            arr[1001] += 1
        else:
            arr[c] += 1

for i in range(jinju + 1, 1002):
    s += arr[i]

print(jinju)
print(s)
