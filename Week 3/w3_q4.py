s = input().strip()
t = input().strip()

n = len(s)
m = len(t)

prev = list(range(m + 1))

for i in range(1, n + 1):
    curr = [0] * (m + 1)
    curr[0] = i

    for j in range(1, m + 1):
        cost = 0 if s[i - 1] == t[j - 1] else 1

        curr[j] = min(
            prev[j] + 1,      # delete
            curr[j - 1] + 1,  # insert
            prev[j - 1] + cost  # replace/match
        )

    prev = curr

print(prev[m])