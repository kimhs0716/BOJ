s = input()
if s[0] == '0' and s[1].isdigit():
    s = '0o' + s[1:]
print(eval(s))