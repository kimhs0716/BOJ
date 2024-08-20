import sys
input = lambda: sys.stdin.readline().rstrip()

while True:
    n, *arr1 = map(int, input().split())
    if n == 0: break
    m, *arr2 = map(int, input().split())

    arr1.reverse()
    arr2.reverse()

    ans = 0
    c = [0, 0]

    while True:
        if not arr1 or not arr2:
            ans += max(c[0] + sum(arr1), c[1] + sum(arr2))
            break

        if arr1[-1] < arr2[-1]:
            c[0] += arr1.pop()
        elif arr2[-1] < arr1[-1]:
            c[1] += arr2.pop()
        else:
            ans += max(c) + arr1.pop()
            arr2.pop()
            c = [0, 0]

    print(ans)
