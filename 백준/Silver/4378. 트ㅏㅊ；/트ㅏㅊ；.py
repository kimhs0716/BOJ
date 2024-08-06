import sys
input = lambda: sys.stdin.readline()[:-1]

key1 = '`1234567890-='
key2 = 'QWERTYUIOP[]\\'
key3 = 'ASDFGHJKL;\''
key4 = 'ZXCVBNM,./'

while True:
    s = input()
    if s == '': break

    result = []
    for i in s:
        if i == ' ': result.append(' ')
        elif i in key1: result.append(key1[key1.index(i) - 1])
        elif i in key2: result.append(key2[key2.index(i) - 1])
        elif i in key3: result.append(key3[key3.index(i) - 1])
        else: result.append(key4[key4.index(i) - 1])
    print(''.join(result))
