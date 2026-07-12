import sys


def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    N, W = int(data[0]), int(data[1])
    items = []

    for i in range(N):
        items.append((int(data[2 * i + 2]), int(data[2 * i + 3])))

    max_v = 100 * 1000
    inf = float("inf")
    dp = [inf] * (max_v + 1)
    dp[0] = 0
    for w, v in items:
        for current_val in range(max_v, v - 1, -1):
            if dp[current_val - v] != inf:
                dp[current_val] = min(dp[current_val], dp[current_val - v] + w)
    max_value_ach = 0
    for val in range(max_v, -1, -1):
        if dp[val] <= W:
            max_value_ach = val
            break
    print(max_value_ach)


if __name__ == "__main__":
    solve()
