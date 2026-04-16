import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.reverse()
    ans = 0
    cur_max = arr[0]
    for i in arr:
        if i < cur_max:
            ans += cur_max - i
        else:
            cur_max = i
    print(ans)
