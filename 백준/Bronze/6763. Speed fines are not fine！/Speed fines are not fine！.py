a = int(input())
b = int(input())
if b - a > 30: f = 500
elif b - a > 20: f = 270
elif b - a > 0: f = 100
else: print("Congratulations, you are within the speed limit!");f = 0
if f: print("You are speeding and your fine is $%d." % f)