dic = { 62: '+', 63: '/' }
for i in range(26):
    dic[i] = chr(i + 65)
    dic[i + 26] = chr(i + 97)
for i in range(10):
    dic[i + 52] = chr(i + 48)
    
def encode(s):
    global dic
    a = 0
    for i in s:
        a <<= 8
        a |= ord(i)
    a <<= (-len(s) % 3) * 2
    result = []
    while a:
        result.append(dic[a & ((1 << 6) - 1)])
        a >>= 6
    ret = ''.join(reversed(result))
    return ret + '=' * (-len(ret) % 4)

print(encode(input()))
