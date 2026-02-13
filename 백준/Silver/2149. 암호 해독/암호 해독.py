import sys
input = lambda: sys.stdin.readline().rstrip()


key = input()
s = input()

key = [(c, i) for i, c in enumerate(key)]
key.sort()
t = [-1] * len(key)
for i in range(len(key)):
    t[key[i][1]] = i
key = t
arr = [[] for _ in key]
for i in range(len(s)):
    arr[i//(len(s)//len(key))].append(s[i])


ans = []
for i in range(len(s)//len(key)):
    for k in key:
        ans.append(arr[k][i])

print(''.join(ans))      
