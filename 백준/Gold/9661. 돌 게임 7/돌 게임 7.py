def g(x):
    return (0, 1, 0, 1, 2)[x % 5]


n = int(input())
print("SK" if g(n) else "CY")
