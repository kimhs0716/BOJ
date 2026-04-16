s = input()
if s[0] == '"' and s[-1] == '"' and s[1:-1]: print(s[1:-1])
else: print('CE')