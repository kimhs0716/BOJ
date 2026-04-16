s = input().split()
common = s[0]
vals = [i[:-1] for i in s[1:]]
for i in range(len(vals)):
    val_type = []
    idx = len(vals[i]) - 1
    while True:
        if vals[i][idx] in '&*':
            val_type.append(vals[i][idx])
        elif vals[i][idx] == ']':
            val_type.append('[]')
            idx -= 1
        else:
            break
        idx -= 1
    val_name = vals[i][:idx + 1]
    vals[i] = (val_name, val_type)
# print(vals)
for i in vals:
    print(common, end='')
    for j in i[1]: print(j, end='')
    print('', i[0] + ';')
