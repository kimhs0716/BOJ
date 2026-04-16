import re
r = re.compile('(100+1+|01)+')
s = input()
if re.fullmatch(r, s):
    print('SUBMARINE')
else:
    print('NOISE')