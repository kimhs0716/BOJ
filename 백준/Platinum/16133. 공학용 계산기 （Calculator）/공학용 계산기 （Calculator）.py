def sqrt(n):
    i = int(n ** 0.5)
    while i * i <= n: i += 1
    return i - 1
def find(arr, item):
    try:
        return arr.index(item)
    except:
        return -1
def ev(expr):
    res = 0
    while expr.count("("):
        for i in range(len(expr)):
            if expr[i] == "(": left = i
            if expr[i] == ")":
                right = i
                break
        expr[left] = ev(expr[left + 1: right])
        for i in range(right - left):
            del expr[left + 1]
    while len(expr) != 1:
        if find(expr, "#") != -1:
            i = len(expr) - 1
            while i >= 0:
                if expr[i] == "#":
                    expr[i] = sqrt(expr[i + 1])
                    del expr[i + 1]
                    i = len(expr) - 1
                    continue
                i -= 1
        if find(expr, "^") != -1:
            i = len(expr) - 1
            while i >= 0:
                if expr[i] == "^":
                    expr[i - 1] = expr[i - 1] ** expr[i + 1]
                    del expr[i], expr[i]
                    i = len(expr) - 1
                    continue
                i -= 1
        if find(expr, "*") != -1 or find(expr, "/") != -1:
            i = 0
            while i < len(expr):
                if expr[i] == "*":
                    expr[i - 1] = expr[i - 1] * expr[i + 1]
                    del expr[i], expr[i]
                    continue
                if expr[i] == "/":
                    expr[i] = int(expr[i - 1] / expr[i + 1])
                    if(expr[i] >= 0): expr[i - 1] = expr[i - 1] // expr[i + 1]
                    else: expr[i - 1] = expr[i - 1] // expr[i + 1] + 1
                    del expr[i], expr[i]
                    continue
                i += 1
        if find(expr, "+") != -1 or find(expr, "-") != -1:
            i = 0
            while i < len(expr):
                if expr[i] == "+":
                    expr[i - 1] = expr[i - 1] + expr[i + 1]
                    del expr[i], expr[i]
                    continue
                if expr[i] == "-":
                    expr[i - 1] = expr[i - 1] - expr[i + 1]
                    del expr[i], expr[i]
                    continue
                i += 1
    return expr[0]
expr = input().replace("+", " + ").replace("-", " - ")\
       .replace("*", " * ").replace("/", " / ")\
       .replace("^", " ^ ").replace("#", " # ")\
       .replace("(", " ( ").replace(")", " ) ")[:-1].split(" ")
expr = list(filter(lambda x: x, expr))
for i in range(len(expr)):
    try:
        expr[i] = int(expr[i])
    except:
        pass
print(ev(expr))
