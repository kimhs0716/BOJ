def numeric(code, l):
    idx = 0
    result = []
    for _ in range(l // 3):
        bit = int(code[idx : idx + 10], 2)
        idx += 10
        result.append('%03d' % bit)
    if l % 3:
        bit = int(code[idx : idx + (0, 4, 7)[l % 3]], 2)
        result.append(('%%0%dd' % (l % 3)) % bit)
    return ''.join(result)
        
def alphanumeric(code, l):
    de = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:'
    idx = 0
    result = []
    for _ in range(l // 2):
        bit = int(code[idx : idx + 11], 2)
        idx += 11
        result.append(de[bit // 45] + de[bit % 45])
    if l & 1:
        bit = int(code[idx : idx + (0, 6)[l % 2]], 2)
        result.append(de[bit])
    return ''.join(result)
        
def byte(code, l):
    de = {}
    for i in range(1 << 8):
        if 0x20 <= i <= 0x7e:
            de[i] = chr(i)
            if de[i] == '#':
                de[i] = '\\#'
        else:
            de[i] = '\\%02X' % i
    idx = 0
    result = []
    for _ in range(l):
        bit = int(code[idx : idx + 8], 2)
        idx += 8
        result.append(de[bit])
    return ''.join(result)

def kanji(code, l):
    idx = 0
    result = []
    for _ in range(l):
        bit = int(code[idx : idx + 13], 2)
        idx += 13
        result.append('#%04X' % bit)
    return ''.join(result)

for _ in range(int(input())):
    a = bin(int(input(), 16))[2:]
    a = '0' * (152 - len(a)) + a 
    idx = 0
    cnt = 0
    result = []
    while True:
        mod_bit = a[idx : idx + 4]
        idx += 4
        if mod_bit == '0000' or idx + 3 >= len(a): break
        elif mod_bit == '0001':
            l = a[idx : idx + 10]
            l = int(l, 2)
            idx += 10
            result.append(numeric(a[idx:], l))
            idx += 10 * (l // 3) + (0, 4, 7)[l % 3]
        elif mod_bit == '0010':
            l = a[idx : idx + 9]
            l = int(l, 2)
            idx += 9
            result.append(alphanumeric(a[idx:], l))
            idx += 11 * (l // 2) + (0, 6)[l % 2]
        elif mod_bit == '0100':
            l = a[idx : idx + 8]
            l = int(l, 2)
            idx += 8
            result.append(byte(a[idx:], l))
            idx += 8 * l
        else:
            l = a[idx : idx + 8]
            l = int(l, 2)
            idx += 8
            result.append(kanji(a[idx:], l))
            idx += 13 * l
        cnt += l
    print(cnt, ''.join(result))
        
