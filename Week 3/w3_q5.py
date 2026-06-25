MOD = 10**9 + 7

t = int(input())
queries = [int(input()) for _ in range(t)]

mx = max(queries)

dp0 = [0] * (mx + 1)
dp1 = [0] * (mx + 1)

dp0[1] = 1
dp1[1] = 1

for i in range(2, mx + 1):
    dp0[i] = (4 * dp0[i - 1] + dp1[i - 1]) % MOD
    dp1[i] = (dp0[i - 1] + 2 * dp1[i - 1]) % MOD

for n in queries:
    print((dp0[n] + dp1[n]) % MOD)