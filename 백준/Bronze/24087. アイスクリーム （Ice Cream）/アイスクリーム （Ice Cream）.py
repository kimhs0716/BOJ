s = int(input())
a = int(input())
b = int(input())
print(max(250, int((s - a + b - 1) // b) * 100 + 250))
