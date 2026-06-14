n,target=map(int,input().split())
m=[int(x) for x in input().split()]
s={}
for i in range(n):
    for j in range(i+1,n):
        k=target-m[i]-m[j]
        if k in s and s[k]!=i+1 and s[k]!=j+1:
            print(f"{s[k]} {i+1} {j+1}")
            exit()

    s[m[i]]=i+1
           

print("IMPOSSIBLE")     
    