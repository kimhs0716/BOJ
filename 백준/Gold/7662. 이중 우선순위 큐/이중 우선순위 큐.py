import sys
input = lambda: sys.stdin.readline().rstrip()


from heapq import heappush, heappop


for _ in range(int(input())):
    n = int(input())
    max_heap = []
    min_heap = []
    cnt = dict()
    total = 0

    for __ in range(n):
        c, x = input().split()
        x = int(x)
        if c == 'I':
            cnt[x] = cnt.get(x, 0) + 1
            heappush(min_heap, x)
            heappush(max_heap, -x)
            total += 1
        else:
            if x == 1:
                t = None
                while True:
                    if total == 0: break
                    t = -heappop(max_heap)
                    if cnt[t] == 0: continue
                    total -= 1
                    cnt[t] -= 1
                    break
            else:
                t = None
                while True:
                    if total == 0: break
                    t = heappop(min_heap)
                    if cnt[t] == 0: continue
                    total -= 1
                    cnt[t] -= 1
                    break

    if total:
        while True:
            M = -heappop(max_heap)
            if cnt[M] == 0: continue
            break
        
        while True:
            m = heappop(min_heap)
            if cnt[m] == 0: continue
            break
        print(M, m)
    else:
        print('EMPTY')
