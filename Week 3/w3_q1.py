n = int(input())

tasks = []

for _ in range(n):
    a, d = map(int, input().split())
    tasks.append((a, d))

# Sort by duration
tasks.sort()

current_time = 0
reward = 0

for a, d in tasks:
    current_time += a
    reward += d - current_time

print(reward)