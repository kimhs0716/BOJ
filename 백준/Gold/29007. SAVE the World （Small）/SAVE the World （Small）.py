import sys
input = lambda: sys.stdin.readline().rstrip()

def solve(x, y, result=""):
    #input(' '.join(map(str, (x, y, result))))
    if x == 0:
        if y == 1:
            return result + 'X'
        if y > 0:
            return solve(x - 1, y - 1, result + 'Z')
        else:
            return  solve(x + 1, y, result + 'D')
    if y <= -x and y > x:
        return solve(x, y - 1, result + 'X')
    elif x >= y and x < -y:
        return solve(x + 1, y, result + 'D')
    elif y >= -x and y < x:
        return solve(x, y + 1, result + 'W')
    else:
        return solve(x - 1, y, result + 'A')

n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    print(solve(x, y))
