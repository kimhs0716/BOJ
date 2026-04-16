import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())

if n % 3 < 2:
    arr1 = [ i for i in range(1, n) if i % 3 ]
    arr2 = [ i for i in range(1, n + 1) if i % 3 == 0 ]

else:
    arr1 = [1] + [ i for i in range(3, n + 1) if i % 3 != 2 ]
    arr2 = [2] + [ i for i in range(3, n + 1) if i % 3 == 2 ]

print(len(arr1))
print(*arr1)
print(len(arr2))
print(*arr2)
