# we have two approach on was to find the compliment of each number and then find the the same number in array. it wa slower
# here we sort the array and then two pointer move from opposite edgses scanning for the sum to be target. 
import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return

    n = int(data[0])
    target = int(data[1])
    arr = [(int(data[i + 2]), i + 1) for i in range(n)]
    arr.sort()
    left = 0
    right = n - 1
    while left < right:
        current_sum = arr[left][0] + arr[right][0]

        if current_sum == target:
            print(f"{arr[left][1]} {arr[right][1]}")
            return

        elif current_sum < target:
            left += 1

        else:
            right -= 1
    print("IMPOSSIBLE")


if __name__ == "__main__":
    solve()
