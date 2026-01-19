import sys
input = lambda: sys.stdin.readline().rstrip()


r, c = map(int, input().split())
arr = [list(input()) for _ in range(r)]

wall = 0
one_dir = 0
all_dir = 0
vac = 0
start = 0
end = 0

for i in arr:
    for j in i:
        if j=='#': wall += 1
        elif j in 'UDLR': one_dir += 1
        elif j=='A': all_dir += 1
        elif j=='V': vac += 1
        elif j=='S': start += 1
        elif j=='E': end += 1

if start!=1 or end!=1:
    print(-1)
elif all_dir == 0:
    if vac == 0:
        if wall<=1 and one_dir<=1:
            print(1)
        else:
            print(2)
    else:
        print(3)
else:
    print(4)
