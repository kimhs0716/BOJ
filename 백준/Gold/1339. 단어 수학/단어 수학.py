def ev(s, ch):
    ret = 0
    i = 1
    for c in reversed(s):
        ret += i * (c == ch)
        i *= 10
    return ret

def solve(sarr):
    alpha = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    arr = {i: 0 for i in alpha}
    for s in sarr:
        temp_arr = {}
        for i in alpha:
            temp_arr[i] = ev(s, i)
        for i in temp_arr:
            arr[i] += temp_arr[i]
    alpha.sort(key=lambda x: -arr[x])
    ret = 0
    for i in range(10):
        ret += arr[alpha[i]] * (9 - i)
    return ret

n = int(input())
arr = []
for i in '_' * n:
    arr.append(input())

print(solve(arr))
