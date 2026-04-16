for _ in range(int(input())):
    x = int(input())
    time = 366
    while time<=24*60 and x>=50:
        time += 12
        x -= 50
    if time > 24*60: print(-1)
    else: print(f"{time//60:02d}:{time%60:02d}")