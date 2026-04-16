def ev(expr):
    while expr.count('+') != 0:
        i = 0
        while i < len(expr):
            if expr[i] == '+':
                expr[i - 1] += expr[i + 1]
                del expr[i]
                del expr[i]
                i -= 1
            i += 1
    while len(expr) != 1:
        i = 0
        while i < len(expr):
            if expr[i] == '-':
                expr[i - 1] -= expr[i + 1]
                del expr[i]
                del expr[i]
                i -= 1
            i += 1
    return expr[0]
expr = input().replace("+", " + ").replace("-", " - ").split(" ")
expr = list(filter(lambda x: x, expr))
for i in range(len(expr)):
    try:
        expr[i] = int(expr[i])
    except:
        pass
print(ev(expr))
