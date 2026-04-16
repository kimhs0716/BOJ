arr = input().split()
x, *_ = input().split()
if x in arr: print(arr.index(x) + 1)
else: print(0)