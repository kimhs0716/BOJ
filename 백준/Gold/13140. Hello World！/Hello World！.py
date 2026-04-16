n = int(input())

arr = []

for h in range(1, 10):
    arr.append(h)
    for e in range(10):
        if e in arr: continue
        arr.append(e)
        for l in range(10):
            if l in arr: continue
            arr.append(l)
            for o in range(10):
                if o in arr: continue
                arr.append(o)
                for w in range(1, 10):
                    if w in arr: continue
                    arr.append(w)
                    for r in range(10):
                        if r in arr: continue
                        arr.append(r)
                        for d in range(10):
                            if d in arr: continue
                            if int("%d%d%d%d%d" % (h, e, l, l, o)) + \
                               int("%d%d%d%d%d" % (w, o, r, l, d)) == n:
                                print("  ", h, e, l, l, o, sep = "")
                                print("+ ", w, o, r, l, d, sep = "")
                                print("-------")
                                print("%7d" % n)
                                exit(0)
                        arr.pop()
                    arr.pop()
                arr.pop()
            arr.pop()
        arr.pop()
    arr.pop()
print("No Answer")
