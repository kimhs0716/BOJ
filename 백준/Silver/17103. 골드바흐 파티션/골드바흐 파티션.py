import sys

input = sys.stdin.readline



def Era(size):

    arr = [1 for _  in range(size+1)]

    

    arr[0] = 0

    arr[1] = 0

    

    inx = 2

    multiplier = 2

    

    while inx<=size:

        multiplier = 2

        if arr[inx] == 1:

            while inx * multiplier <= size:

                arr[inx * multiplier] = 0

                multiplier = multiplier + 1

        inx = inx + 1

    return arr

                

num = []



for _ in range(int(input().rstrip())):

    num.append(int(input().rstrip()))

    

MAX = max(num)



prime = Era(MAX)

dic = {}



for inx, x in enumerate(prime):

    if x == 1:

        dic[inx]=True



for k in num:

    count = 0

    for t in dic:

        if t>(k//2):

            break

        else:

            if (k-t) in dic:

                #print(f"k,t = :{k,t,k-t}") 디버깅용코드

                count = count + 1

    print(count)