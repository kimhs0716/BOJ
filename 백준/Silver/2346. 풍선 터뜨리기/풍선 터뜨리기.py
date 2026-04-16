from collections import deque

n = int(input())
d = deque(enumerate(map(int, input().split())))

while d:
    # print(d)
    print(d[0][0] + 1)
    k = d[0][1]
    d.popleft()
    if not d: break
    for _ in range(abs(k) - 1):
        if k > 0: d.append(d.popleft()) 
        else: d.appendleft(d.pop())
    if k < 0: d.appendleft(d.pop())
