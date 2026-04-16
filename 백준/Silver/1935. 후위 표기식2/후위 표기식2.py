import string

n = int(input())
nums = []
s = input()
arr = [int(input()) for _ in range(n)]

for i in s:
    if i in string.ascii_uppercase:
        nums.append(arr[ord(i) - ord('A')])
    else:
        n1 = nums.pop()
        n2 = nums.pop()
        nums.append(eval(f'{n2}{i}{n1}'))

print('{:.2f}'.format(nums[0]))