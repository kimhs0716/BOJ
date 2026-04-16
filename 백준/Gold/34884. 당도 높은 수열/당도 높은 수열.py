import random

n = 150000
arr = list(range(1, n+1))
random.shuffle(arr)
print(*arr)
