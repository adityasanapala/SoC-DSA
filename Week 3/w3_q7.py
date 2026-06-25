import heapq

x, n = map(int, input().split())
pieces = list(map(int, input().split()))

heapq.heapify(pieces)

cost = 0

while len(pieces) > 1:
    a = heapq.heappop(pieces)
    b = heapq.heappop(pieces)

    s = a + b
    cost += s

    heapq.heappush(pieces, s)

print(cost)