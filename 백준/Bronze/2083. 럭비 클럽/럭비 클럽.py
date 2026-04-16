import sys
input = lambda: sys.stdin.readline().rstrip()


while True:
    n, a, w = input().split()
    if n=='#': break
    if int(a)>17 or int(w)>=80: print(n, 'Senior')
    else: print(n, 'Junior')
