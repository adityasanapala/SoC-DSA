MOD = 998244353

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # Maximum possible value after each step
    mx = 0

    # Number of ways to obtain current maximum
    ways = 1

    for x in a:
        nxt = mx + x

        if nxt >= 0:
            # Both operations give the same value
            mx = nxt
            ways = (ways * 2) % MOD
        else:
            # Option 1 -> nxt
            # Option 2 -> -nxt
            # Maximum is |-nxt|
            mx = -nxt
            # Only option2 keeps the maximum
            # ways unchanged

    print(ways % MOD)