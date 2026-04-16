import sys
sys.set_int_max_str_digits(31000)
n = int(input())
s = str(2 ** n)
if len(s) <= 4300:
    print(s)
