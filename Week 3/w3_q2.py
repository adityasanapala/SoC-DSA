n, t = map(int, input().split())
machines = list(map(int, input().split()))

def can_make(time):
    products = 0

    for k in machines:
        products += time // k
        if products >= t:
            return True

    return False

left = 0
right = min(machines) * t

while left < right:
    mid = (left + right) // 2

    if can_make(mid):
        right = mid
    else:
        left = mid + 1

print(left)