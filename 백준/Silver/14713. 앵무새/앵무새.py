import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = [input().split() for _ in range(n)]
s = input().split()

idx = [0] * n
for w in s:
    for i in range(n):
        if idx[i] < len(arr[i]) and arr[i][idx[i]]==w:
            idx[i] += 1
            break
    else:
        print("Impossible")
        exit(0)
if all(map(lambda x: idx[x] == len(arr[x]), range(n))):
    print("Possible")
else:
    print("Impossible")
