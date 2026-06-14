n=int(input())
m=[int(x) for x in input().split()]
k=[]
num=0
maxi=0
for i in range(n):
    if m[i] not in k :
        k.append(m[i])
        num=num+1
        maxi=max(num,maxi)
        
    elif m[i] in k:
        h=k.index(m[i])
        k=k[h+1:]
        k.append(m[i])
        num=num-h
        maxi=max(num,maxi)
        
        
print(maxi)



