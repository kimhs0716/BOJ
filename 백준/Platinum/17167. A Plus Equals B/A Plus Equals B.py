a, b = map(int, input().split())
count = 0
res = []
while a != b:
    while a & 1 == 0 and b & 1 == 0:
        a >>= 1
        b >>= 1
    if a & 1 and b & 1 == 0:
        res.append("A+=A")
        a += a
    elif b & 1 and a & 1 == 0:
        res.append("B+=B")
        b += b
    elif a < b:
        res.append("B+=A")
        b += a
    else:
        res.append("A+=B")
        a += b
    count += 1
print(count)
print("\n".join(res))
