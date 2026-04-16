def selectionSort(arr, cmp=None):
    if cmp is None:
        cmp = lambda a, b: a > b
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if cmp(arr[j], arr[i]):
                arr[i], arr[j] = arr[j], arr[i]


n, k = map(int, input().split())
arr = [input() for _ in range(n)]
selectionSort(arr, cmp=lambda a, b: a + b > b + a)
arr.sort(key=lambda x: -len(x))
arr2 = arr[:k]
if n < k:
    for i in range(k - n):
        arr2.append(arr[0])
selectionSort(arr2, cmp=lambda a, b: a + b > b + a)
print(''.join(arr2))
