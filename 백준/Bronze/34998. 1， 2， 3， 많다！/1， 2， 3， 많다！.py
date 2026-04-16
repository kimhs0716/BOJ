for _ in range(int(input())):
    input()
    expr = input().replace('!', '10')
    ans = eval(expr)
    print(ans if ans < 10 else '!')