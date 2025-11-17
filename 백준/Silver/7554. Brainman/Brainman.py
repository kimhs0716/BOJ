for _ in range(int(input())):
    n, *arr = map(int, input().split())
    ans = 0
    for i in range(n):
        for j in range(i+1, n):
            if arr[i]>arr[j]: ans += 1
    print(f"Scenario #{_+1}:")
    print(ans)
    print()