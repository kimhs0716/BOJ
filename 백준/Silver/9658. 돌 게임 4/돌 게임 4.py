def g(n):
    return n % 7 in (0, 2, 4, 5, 6)

n = int(input())
print("SK" if g(n) else "CY")
