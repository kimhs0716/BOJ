n = int(input())
arr = list(range(1, n + 1))
while len(arr) != 1:
    arr = arr[1::2]
print(arr[0])
