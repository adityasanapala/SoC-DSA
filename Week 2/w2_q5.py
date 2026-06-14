n=int(input())
m=[int(x) for x in input().split()]
m=sorted(m)
if len(m)%2==0:
    length=(m[len(m)//2]+m[len(m)//2-1])/2
else:
    length=m[len(m)//2]

cost=0
for i in range(n//2):
    m[i] = length - m[i]
    cost = cost + m[i]


for i in range(n//2,n):
    m[i] = m[i] - length
    cost = cost + m[i]

print(int(cost))




