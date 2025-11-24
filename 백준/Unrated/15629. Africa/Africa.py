ans = 0
sa = False
prev = ""
for _ in range(int(input())):
    cur = input()
    if cur=="zambia":
        ans += 20 if prev=="zimbabwe" else 50
    elif cur=="zimbabwe":
        if prev!="zambia": ans += 30  
    elif cur=="south-africa": sa = True
    elif cur=="namibia":
        ans += -100*sa + 140
    elif cur in ("ethiopia", "kenya", "tanzania"): ans += 50
    prev = cur
print(ans)