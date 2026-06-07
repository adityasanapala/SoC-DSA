import sys
def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    arr = [int(data[i + 1]) for i in range(n)]
    arr.sort()
    tar=arr[n//2]
    sum_=0
    for i in range(n):
        diff=arr[i]-tar
        sum_+=abs(diff)
    return sum_    
if __name__=="__main__":
    print(solve())    