res = []
input()
for i in input():
    if i=='J': res.append('O')
    if i=='O': res.append('I')
    if i=='I': res.append('J')
print(''.join(res))