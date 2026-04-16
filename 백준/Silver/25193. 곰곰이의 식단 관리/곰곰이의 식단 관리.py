n = int(input())
s = input()
print(s.count('C') // (n - s.count('C') + 1) + (s.count('C') % (n - s.count('C') + 1) != 0))
