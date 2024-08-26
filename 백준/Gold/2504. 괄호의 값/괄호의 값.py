class Stack:
    def __init__(self):
        self.arr = []
        self.count = 0
    def push(self, item):
        self.arr.append(item)
        self.count += 1
    def pop(self):
        if self.empty(): return -1
        self.count -= 1
        return self.arr.pop()
    def size(self):
        return self.count
    def empty(self):
        return self.count == 0
    def top(self):
        if self.empty(): return -1
        return self.arr[-1]
    
def ev(expr):
    if expr == '': return 0
    if expr == '()': return 2
    if expr == '[]': return 3
    if expr[0] == '(':
        i = 0
        count = 1
        while count != 0 or expr[i] != ')':
            i += 1
            if expr[i] == '(': count += 1
            if expr[i] == ')': count -= 1
        if expr[1:i] == '': return 2 + ev(expr[i + 1:])
        if expr[i + 1:] == '': return 2 * ev(expr[1:i])
        return 2 * ev(expr[1:i]) + ev(expr[i + 1:])
    if expr[0] == '[':
        i = 0
        count = 1
        while count != 0 or expr[i] != ']':
            i += 1
            if expr[i] == '[': count += 1
            if expr[i] == ']': count -= 1
        if expr[1:i] == '': return 3 + ev(expr[i + 1:])
        if expr[i + 1:] == '': return 3 * ev(expr[1:i])
        return 3 * ev(expr[1:i]) + ev(expr[i + 1:])
    

stack = Stack()
expr = input()
stack.push(expr[0])
for i in range(1, len(expr)):
    if stack.top() == '(':
        if expr[i] == ')':
            stack.pop()
            continue
        if expr[i] == ']':
            print(0)
            exit(0)
        stack.push(expr[i])
    elif stack.top() == '[':
        if expr[i] == ']':
            stack.pop()
            continue
        if expr[i] == ')':
            print(0)
            exit(0)
        stack.push(expr[i])
    elif stack.empty():
        stack.push(expr[i])
if not stack.empty():
    print(0)
    exit(0)
print(ev(expr))
