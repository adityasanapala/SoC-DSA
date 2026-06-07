# here two pointers work together to slide through the array, right leads by taking new inputs and left one will only shift is the new entry
#  has appeared in the seen{} before 
import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    last_seen = {}
    left = 0
    max_len = 0
    for right in range(n):
        song = data[right + 1]
        if song in last_seen and last_seen[song] >= left:
            left = last_seen[song] + 1
        last_seen[song] = right
        leng = right + 1 - left
        max_len = max(max_len, leng)
    print(max_len)


if __name__ == "__main__":
    solve()