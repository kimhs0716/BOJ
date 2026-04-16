from math import factorial as fac
n = int(input())

a = list(map(int, input().split()))
if a[0] == 1:
    k = a[1] - 1
    arr = list(range(1, n + 1))
    ans = []
    f = fac(n)
    if k >= f:
        print(-1)
        exit(0)
    for i in range(n):
        f //= n
        n -= 1
        ans.append(arr[k // f])
        arr.pop(k // f)
        k %= f
    print(*ans)
else:
    ans = 1
    next = 1
    arr = [0] * (n + 1)
    f = fac(n - 1)
    for i in range(1, n + 1):
        t = 0
        for j in range(next + 1, a[i] + 1):
            if arr[j] == 0: t += 1
        ans += f * t
        arr[a[i]] = 1
        # print(next, a[i], f, t, ans, arr)
        if n != i: f //= (n - i)
        for next in range(1, n + 1):
            if arr[next] == 0: break
    print(ans)
