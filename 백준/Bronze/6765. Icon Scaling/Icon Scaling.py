import sys
input = lambda: sys.stdin.readline().rstrip()


icon = ['*x*', ' xx', '* *']
n = int(input())
for i in icon:
    line = ''.join(ch*n for ch in i)
    for _ in range(n): print(line)
    
