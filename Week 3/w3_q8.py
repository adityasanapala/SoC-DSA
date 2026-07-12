import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:]]

    max_heap = []
    total_cost = 0
    
    for x in a:
        heapq.heappush(max_heap, -x)
        largest_seen = -max_heap[0]

        if largest_seen > x:
            total_cost += largest_seen - x
            heapq.heappop(max_heap)
            heapq.heappush(max_heap, -x)
            
    print(total_cost)

if __name__ == '__main__':
    solve()