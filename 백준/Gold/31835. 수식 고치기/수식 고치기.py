import sys
input = lambda: sys.stdin.readline().rstrip()


# 마지막을 |T 또는 &F로 바꾸면 되므로 답은 최대 2

def evaluate(arr):
    ret = arr[0] == 'T'
    i = 1
    while i < len(arr):
        op, v = arr[i], arr[i + 1]
        if op == '|':
            ret |= (v == 'T')
        else:
            ret &= (v == 'T')
        i += 2
    return ret

n = int(input())
arr = input().split()
target = (input() == 'T')

if evaluate(arr) == target:
    print(0)

else:
    for i in range(n):
        temp = arr[i]
        if i % 2 == 1:
            arr[i] = '|&'[temp == '|']
        else:
            arr[i] = 'TF'[temp == 'T']
        if evaluate(arr) == target:
            print(1)
            break
        arr[i] = temp
    else:
        print(2)
