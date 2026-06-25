#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int evenCount=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if (i < 3 && a[i] % 2 == 0)
            evenCount++;
    }
    bool majorityEven;
    if(evenCount>=2){
        majorityEven=true;
    }
    else{
        majorityEven=false;
    }
    for (int i = 0; i < n; i++) {
        if (majorityEven && a[i] % 2 != 0) {
            cout << i + 1<<"\n";
            break;
        }

        if (!majorityEven && a[i] % 2 == 0) {
            cout << i + 1<<"\n";
            break;
        }
    }
}