import sys
input = sys.stdin.readline
n, m = map(int, input().split())
name2num = {}
num2name = {}
for i in range(1, n + 1):
    name = input()
    name2num[name] = i
    num2name[i] = name
for i in range(m):
    q = input()
    try:
        print(num2name[int(q)].strip())
    except:
        print(name2num[q])
