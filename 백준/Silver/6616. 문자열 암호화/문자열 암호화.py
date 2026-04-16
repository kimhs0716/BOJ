while (n := int(input())) != 0:
    s = input().replace(' ', '').upper()
    ans = [0] * len(s)
    idx = 0
    idx2 = 0
    for i in range(len(s)):
        ans[idx] = s[i]
        idx += n
        if idx >= len(s):
            idx2 += 1
            idx = idx2
    print(''.join(ans))
