import sys
import heapq


def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    x, n = int(data[0]), int(data[1])
    d = list(map(int, data[2:]))
    heapq.heapify(d)
    cost = 0
    while len(d) > 1:
        first = heapq.heappop(d)
        second = heapq.heappop(d)
        cost += first + second
        heapq.heappush(d, first + second)
    print(cost)


if __name__ == "__main__":
    solve()
