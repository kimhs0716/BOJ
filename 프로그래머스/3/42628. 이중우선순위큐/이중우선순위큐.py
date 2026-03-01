from heapq import heappush as push, heappop as pop

def solution(operations):    
    assert len(operations) <= 100000
    
    max_heap = []
    min_heap = []
    cnt = dict()
    total = 0
    
    for query in operations:
        a, b = query.split()
        if a=="I":
            b = int(b)
            push(max_heap, -b)
            push(min_heap, b)
            cnt[b] = cnt.get(b, 0)+1
            total += 1
        else:
            if total == 0: continue
            if b=="1":
                while True:
                    x = -pop(max_heap)
                    if cnt[x]==0: continue
                    cnt[x] -= 1
                    total -= 1
                    break
            else:
                while True:
                    x = pop(min_heap)
                    if cnt[x]==0: continue
                    cnt[x] -= 1
                    total -= 1
                    break
            
    ans = [0, 0]
    if total == 0: return ans
    while True:
        x = -pop(max_heap)
        if cnt[x] == 0: continue
        ans[0] = x
        break
    while True:
        x = pop(min_heap)
        if cnt[x] == 0: continue
        ans[1] = x
        break
    
    return ans