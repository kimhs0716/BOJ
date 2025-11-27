h, m, s = map(int, input().split(':'))
cur = h*3600 + m*60 + s
h, m, s = map(int, input().split(':'))
start = h*3600 + m*60 + s
t = start - cur
w, k = map(int, input().split())
if w*(100-k) <= 100*t: print(1)
else: print(0)