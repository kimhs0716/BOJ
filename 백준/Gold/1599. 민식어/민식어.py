import sys
input = lambda: sys.stdin.readline().rstrip()


abc = "a b k d e g h i l m n * o p r s t u w y".split()
order = dict()
for i, ch in enumerate(abc):
    order[ch] = i


n = int(input())
arr = [input() for _ in range(n)]

def key(s):
    return list(map(order.get, s.replace("ng", "*")))
    
print(*sorted(arr, key=key), sep='\n')
