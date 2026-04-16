from string import ascii_lowercase
for _ in range(int(input())):
    s = set(ascii_lowercase)
    for i in input().lower():
        s.discard(i)
    if s: print('missing', ''.join(sorted(s)))
    else: print('pangram')