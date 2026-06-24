#include<bits/stdc++.h>
using namespace std;

int main(){
    double a, v;
    cin>>a>>v;
    double l, d, w;
    cin>>l>>d>>w;
    double t1 = 0;
    double t2 = 0;
    double t = 0;
    if(w >= v || sqrt(2*a*d) <= w){
        if(((v*v)/(2*a)) < l) t = (v/a) + ((l-((v*v)/(2*a)))/v);
        if(((v*v)/(2*a)) == l) t = v/a;
        if(((v*v)/(2*a)) > l) t = sqrt((2*l)/a);
        cout<<fixed<<setprecision(9)<<t<<endl;
    }else{
        if((((v*v) - (w*w))/(2*a)) < (l-d)){
            t1 = (v-w)/a + ((l-d) - (((v*v) - (w*w))/(2*a)))/v;
        }
        if((((v*v) - (w*w))/(2*a)) == (l-d)){
            t1 = (v-w)/a;
        }
        if((((v*v) - (w*w))/(2*a)) > (l-d)){
            t1 = ((((-2)*w) + sqrt((4*w*w) + (8*a*(l-d))))/(2*a));
        }
        double u = sqrt(a*d + w*w/2);
        if(u <= v){
            t2 = u/a + (u-w)/a;
        }else{
            double x = d - (v*v)/(2*a) - (v*v - w*w)/(2*a);
            t2 = v/a + x/v + (v-w)/a;  
        }
        cout<<fixed<<setprecision(9)<<t1+t2<<endl;
    }
    return 0;
}