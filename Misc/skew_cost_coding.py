'''
Project Euler 219 - Skew cost coding
'''
# Number of testcases
t = int(input())
for _ in range(t):
    # q[0] is number of elements in the prefix free sequence, q[1] is weight of 0 and q[2] is weight of 1
    q = [int(x) for x in input().split(' ')]
    # Make a sufficiently large list to hold the number of elements in the prefix free sequence that have a particular cost
    # The cost is the indice, and the value is the elements in the sequence that have that cost.
    cost = [0]*1000

    # Inserting a 0 and 1 into the prefix sequence
    cost[q[1]] += 1
    cost[q[2]] += 1

    # The current minimum cost
    curr = min(q[1], q[2])

    # The number of remaining elements in the sequence that have to be found
    rem = q[0]-2
    total = q[1]+q[2]
    while(rem > 0):
        # Find the lowest cost that has some elements with that cost
        while(cost[curr] == 0):
            curr += 1

        # The number of elements with that minimum cost
        elemsWithMinCost = cost[curr]
        if(elemsWithMinCost > rem):
            elemsWithMinCost = rem

        rem -= elemsWithMinCost
        cost[curr] -= elemsWithMinCost
        cost[curr+q[1]] += elemsWithMinCost
        cost[curr+q[2]] += elemsWithMinCost
        total += elemsWithMinCost*(curr+q[1]+curr+q[2]-curr)
    print(total % 1000000007)
