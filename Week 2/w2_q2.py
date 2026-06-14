n,target=map(int,input().split())
m=[int(x) for x in input().split()]
s={} #dictonary
for i in range(n):
    
    j=target-m[i]
    if j  in s:
        print(f"{s[j]} {i+1}")
        exit()
    
    
    else:
        s[m[i]]=i+1
    
print("IMPOSSIBLE")


