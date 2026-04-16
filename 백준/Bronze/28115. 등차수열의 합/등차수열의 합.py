import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
arr = list(map(int, input().split()))

if n == 1:
    print("YES", arr[0], 0, sep='\n')
else:
    d = arr[1] - arr[0]
    for i in range(1, n):
        if arr[i] - arr[i - 1] != d:
            print("NO")
            break
    else:
        print("YES")
        print(*arr)
        print(*([0] * n))
