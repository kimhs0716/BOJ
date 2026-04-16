import random

A = set(range(1, 10001))
B = set(range(1, 10001))

ans = [0, 0]

while True:
    if len(A) == 1 or ans[0] != 0: break
    while True:
        a = random.randint(1, 10000)
        if a in A: break
    print(f'? A {a}')
    if int(input()) == 1:
        ans[0] = a
        continue
    A.discard(a)
if len(A) == 1: ans[0] = list(A)[0]
while True:
    if len(B) == 1 or ans[1] != 0: break
    while True:
        b = random.randint(1, 10000)
        if b in B: break
    print(f'? B {b}')
    if int(input()) == 1:
        ans[1] = b
        continue
    B.discard(b)
if len(B) == 1: ans[1] = list(B)[0]
print(f'! {sum(ans)}')
