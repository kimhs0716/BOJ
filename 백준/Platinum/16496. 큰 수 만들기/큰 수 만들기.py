def bubbleSort(arr, cmp=None):
    if cmp is None:
        cmp = lambda a, b: a > b
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if cmp(arr[j], arr[i]):
                arr[i], arr[j] = arr[j], arr[i]


n = int(input())
arr = input().split()
bubbleSort(arr, cmp=lambda a, b: a + b > b + a)
print(int(''.join(arr)))