n = int(input())
arr = [input() for _ in range(n)]
s = set(arr) - set('?')
m = int(input())
arr2 = [input() for _ in range(m)]

if n == 1:
    print(arr2[0])

elif arr[0] == '?':
    i = arr.index('?')
    l = arr[i + 1][0]
    for j in arr2:
        if j not in s and j[-1] == l:
            print(j)
            break

elif arr[-1] == '?':
    i = arr.index('?')
    f = arr[i - 1][-1]
    for j in arr2:
        if j not in s and j[0] == f:
            print(j)
            break

else:
    i = arr.index('?')
    f = arr[i - 1][-1]
    l = arr[i + 1][0]
    for j in arr2:
        if j not in s and j[0] == f and j[-1] == l:
            print(j)
            break
