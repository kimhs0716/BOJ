M = 0
for _ in range(int(input())):
    s = input()
    M = max(M, s.count("for") + s.count("while"))
print(M)
