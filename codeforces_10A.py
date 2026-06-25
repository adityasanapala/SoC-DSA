
def power_cal(t,t1,t2,p1,p2,p3):
    power=0
    if (t<t1):
        power+=p1*t
    elif(t<=t1+t2):
        power+=p2*(t-t1)+p1*t1
    else:
        power+=p3*(t-t2-t1)+p2*(t2)+p1*t1
    
    return power
 
 
 
n,p1,p2,p3,t1,t2 = map(int,input().split())
power=0
 
for i in range(n):
    l,r=map(int,input().split())
    if (i>0):
        power+=power_cal(l-b,t1,t2,p1,p2,p3)
        
    power+=p1*(r-l)
    b=r
    
print(power)