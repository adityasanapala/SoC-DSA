import sys
def solve():
    data=sys.stdin.read().split()
    n=int(data[0])
    ad=[[int(data[2*i+1]),int(data[2*i+2])] for i in range(n)]
    ad.sort()
    time_passed=0
    points=0
    for i in range(n):
        time_passed+=ad[i][0]
        points+=ad[i][1]-time_passed
    print(points)


if __name__=="__main__" :
    solve()   