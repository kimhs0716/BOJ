def merge_sort(arr, start=0, end=None):
    if end is None: end = len(arr)
    if start + 1 >= end: return
    mid = (start + end) // 2
    merge_sort(arr, start, mid)
    merge_sort(arr, mid, end)
    merge(arr, start, mid, end)

def merge(arr, start, mid, end):
    temp = [0] * (end - start)
    i, j, idx = start, mid, 0
    while i != mid or j != end:
        if i != mid and (j == end or cmp(arr[j], arr[i])):
            temp[idx] = arr[i]
            i += 1
        else:
            temp[idx] = arr[j]
            j += 1
        idx += 1
    for i in range(start, end):
        arr[i] = temp[i - start]


def cmp1(a, b):
    a = cache[a]
    b = cache[b]
    return a + b > b + a

def cmp2(a, b):
    a = cache[a]
    b = cache[b]
    if len(a) == len(b):
        return a + b > b + a
    return len(a) > len(b)

cache = dict()
n = int(input())
arr = input().split()
for i in range(n):
    s = list(arr[i])
    for j in range(len(s)):
        if s[j] == '6': s[j] = '9'
        elif s[j] == '9': s[j] = '6'
    cache[arr[i]] = ''.join(reversed(s))

cmp = cmp2
merge_sort(arr)
arr.append(arr[-1])

cmp = cmp1
merge_sort(arr)
print(''.join(arr))
