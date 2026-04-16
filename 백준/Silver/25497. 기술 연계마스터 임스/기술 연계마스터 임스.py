n = int(input())
st = __import__('sys').stdin.readline().rstrip()
s, l = 0, 0
cnt = 0
for i in st:
    if i == 'L': l += 1
    elif i == 'S': s += 1
    elif i == 'K':
        if s <= 0: break
        s -= 1
    elif i == 'R':
        if l <= 0: break
        l -= 1
    if i not in 'LS': cnt += 1
print(cnt)
