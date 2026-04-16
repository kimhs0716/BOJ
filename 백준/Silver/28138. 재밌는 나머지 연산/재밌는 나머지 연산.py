n, r = map(int, input().split())

n -= r

i = 1

cnt = 0

while i * i < n:

	if n % i == 0:		# print(i)

		if i > r:

			cnt += i

		if n // i > r:

			cnt += n // i

	i += 1

if i * i == n and i > r:

	cnt += i

print(cnt)