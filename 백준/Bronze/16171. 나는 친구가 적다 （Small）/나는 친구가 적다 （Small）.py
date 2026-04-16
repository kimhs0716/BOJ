s = ''.join(i for i in input() if not i.isdigit())
p = input()
print(int(p in s))