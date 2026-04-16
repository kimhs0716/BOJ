import sys
input = lambda: sys.stdin.readline().rstrip()


from string import ascii_lowercase, ascii_uppercase

def check(s):
    cnt = [0, 0]
    for c in s:
        if c in ascii_uppercase: cnt[0] += 1
        elif c in ascii_lowercase: cnt[1] += 1
    flag = False
    for c in s:
        if not c.isdigit():
            flag = True

    return (cnt[1] >= cnt[0]) + (len(s) <= 10) + flag

for _ in range(int(input())):
    s = input()
    if check(s) == 3:
        print(s)
        break
