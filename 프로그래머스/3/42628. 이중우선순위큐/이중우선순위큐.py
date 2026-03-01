def solution(operations): 
    answer = [] 
    for i in operations: 
        if i[0] == 'I': 
            answer.append(int(i[1:])) 
            answer.sort() 
        elif i[0] == 'D': 
            if not answer: 
                continue 
            elif i[2] == '-': 
                answer.pop(0) 
            else: answer.pop() 
    if not answer: 
        return [0, 0] 
    else: 
        return [answer[-1], answer[0]]

# from heapq import heappush as push, heappop as pop

# def solution(operations):    
#     max_heap = []
#     min_heap = []
#     cnt = dict()
#     total = 0
    
#     for query in operations:
#         a, b = query.split()
#         if a=="I":
#             b = int(b)
#             push(max_heap, -b)
#             push(min_heap, b)
#             cnt[b] = cnt.get(b, 0)+1
#             total += 1
#         else:
#             if total == 0: continue
#             if b=="1":
#                 while True:
#                     x = -pop(max_heap)
#                     if cnt[x]==0: continue
#                     cnt[x] -= 1
#                     total -= 1
#                     break
#             else:
#                 while True:
#                     x = pop(min_heap)
#                     if cnt[x]==0: continue
#                     cnt[x] -= 1
#                     total -= 1
#                     break
            
#     ans = [0, 0]
#     if total == 0: return ans
#     while True:
#         x = -pop(max_heap)
#         if cnt[x] == 0: continue
#         ans[0] = x
#         break
#     while True:
#         x = pop(min_heap)
#         if cnt[x] == 0: continue
#         ans[1] = x
#         break
    
#     return ans