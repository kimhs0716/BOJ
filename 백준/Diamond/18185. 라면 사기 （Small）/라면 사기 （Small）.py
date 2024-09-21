# Read input
N = int(input())
A = list(map(int, input().split()))
A += [0, 0]  # Extend the list to avoid index errors

total_cost = 0

for i in range(N):
    # Step 1: Handle excess ramen at A[i+1] by applying Option 2
    if A[i+1] > A[i+2]:
        times = min(A[i], A[i+1] - A[i+2])
        A[i] -= times
        A[i+1] -= times
        total_cost += 5 * times

    # Step 2: Apply Option 3 as much as possible
    times = min(A[i], A[i+1], A[i+2])
    if times > 0:
        A[i] -= times
        A[i+1] -= times
        A[i+2] -= times
        total_cost += 7 * times

    # Step 3: Apply Option 2 again if possible
    times = min(A[i], A[i+1])
    if times > 0:
        A[i] -= times
        A[i+1] -= times
        total_cost += 5 * times

    # Step 4: Purchase remaining ramen at A[i] using Option 1
    if A[i] > 0:
        total_cost += 3 * A[i]
        A[i] = 0

# Output the total cost
print(total_cost)
