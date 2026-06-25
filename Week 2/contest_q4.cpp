#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double a,v,l,d,w;
    cin>>a>>v>>l>>d>>w;
    double t=0;
    if(v<=w||d<0.5*w*w/a){
        if(l>0.5*v*v/a){
            double s = 0.5*v*v/a;
            t= v/a + (l-s)/v;
        }
        else{
            t=sqrt(2*l/a);
        }
    }
    else{
        double t1 = 0.0;

        double u = sqrt((2.0 * a * d + w * w) / 2.0);

        if (u <= v) {
            t1 = u / a + (u - w) / a;
        } 
        else {
            double s1 = v * v / (2.0 * a);
            double s2 = (v * v - w * w) / (2.0 * a);

            t1 += v / a;
            t1 += (d - s1 - s2) / v;
            t1 += (v - w) / a;
        }

        double x = l - d;

        double s = (v * v - w * w) / (2.0 * a);

        double t2;

        if (x <= s) {
            double vf = sqrt(w * w + 2.0 * a * x);
            t2 = (vf - w) / a;
        } else {
            t2 = (v - w) / a;
            t2 += (x - s) / v;
        }

        t = t1 + t2;
    }
    cout<<fixed<<setprecision(10)<<t<<"\n";
}