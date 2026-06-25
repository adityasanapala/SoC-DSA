N, W = map(int, input().split())

items = []
max_value = 0

for _ in range(N):
    w, v = map(int, input().split())
    items.append((w, v))
    max_value += v

INF = 10**18

dp = [INF] * (max_value + 1)
dp[0] = 0

for w, v in items:
    for value in range(max_value, v - 1, -1):
        dp[value] = min(dp[value], dp[value - v] + w)

ans = 0

for value in range(max_value + 1):
    if dp[value] <= W:
        ans = value

print(ans)