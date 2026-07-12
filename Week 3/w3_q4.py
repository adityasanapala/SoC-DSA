def min_edit_distance(s1: str, s2: str) -> int:
    m = len(s1)
    n = len(s2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        dp[i][0] = i

    for j in range(n + 1):
        dp[0][j] = j

    for i in range(1, m + 1):
        for j in range(1, n + 1):

            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

    return dp[m][n]


if __name__ == "__main__":
    import sys

    input_data = sys.stdin.read().split()

    if len(input_data) >= 2:
        string1 = input_data[0]
        string2 = input_data[1]
        print(min_edit_distance(string1, string2))
