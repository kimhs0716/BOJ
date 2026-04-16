import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
a = input()
b = input()
aw = a.count('w')
bw = b.count('w')

if a==b: ans = "Good"
elif aw==bw: ans = "Its fine"
elif aw<bw: ans = "Manners maketh man"
else: ans = "Oryang"

print(ans)