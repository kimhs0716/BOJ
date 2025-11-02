import heapq

n = int(input())
s = []
for i in range(n):
    heapq.heappush(s, input() + "a")

ans = []
while s:
    t = heapq.heappop(s)
    if t != "a": 
        ans.append(t[0])
        if len(t) > 1: heapq.heappush(s, t[1:])
print(''.join(ans))
