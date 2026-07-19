import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    s = input().strip()

    # x must have at least two digits (given)
    digits = list(map(int, s[::-1]))  # reverse for easier processing
    n = len(digits)

    # dp[pos][carry]
    dp = [[False] * 2 for _ in range(n + 1)]
    dp[0][0] = True

    for i in range(n):
        for carry in range(2):
            if not dp[i][carry]:
                continue

            for a in range(5, 10):
                for b in range(5, 10):
                    total = a + b + carry
                    if total % 10 == digits[i]:
                        new_carry = total // 10
                        dp[i + 1][new_carry] = True

    # No carry should remain after the most significant digit
    print("YES" if dp[n][0] else "NO")