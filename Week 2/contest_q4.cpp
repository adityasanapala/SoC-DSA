#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int a,v,l,d,w;
    cin>>a>>v>>l>>d>>w;
    double t,s,t4;
    s=1.0*v*v/a-1.0*w*w/(2.0*a);
    double t2=1.0*d/w+1.0*w/(2.0*a);
    if((l-d)>v*v/(2.0*a)-w*w/(2.0*a)) t4=1.0*(l-d-v*v/(2.0*a)+w*w/(2.0*a))/v+1.0*(v-w)/a;
    else t4=1.0*(sqrt(1.0*w*w+2.0*a*(l-d))-w)/a;
    if(w>=v){
        if(l>(v*v)/(2.0*a))t=1.0*l/v+v/(2.0*a);
        else t=sqrt(2.0*l/a);
    }
    else{
        if(d<=s){
            if(d>1.0*w*w/(2*a)){
                double u=sqrt(1.0*a*d+1.0*w*w/2.0);
                double t1=2.0*u/a-1.0*w/a;
                t=min(t1,t2)+t4;
            }
            else{
                if(l>(v*v)/(2.0*a))t=1.0*l/v+v/(2.0*a);
                else t=sqrt(2.0*l/a);
            }
        }
        else{
            double t3=2.0*v/a-1.0*w/a+1.0*(d-s)/v;
            t=min(t2,t3)+t4;
        }
    }
    cout<<fixed<<setprecision(5);
    cout<<t<<'\n';
}