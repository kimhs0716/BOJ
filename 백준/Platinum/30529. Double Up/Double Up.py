import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
arr = list(map(int, input().split()))

while True:
    st = []
    for i in arr:
        while st and st[-1]==i:
            st.pop()
            i <<= 1
        st.append(i)
    # print(arr, st)
    m = min(arr)
    arr = [i for i in st if i != m]
    if not arr:
        print(m)
        break
