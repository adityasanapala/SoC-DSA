#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int center = (k+1)/2;
    vector<vector<bool>> occupied(k+1, vector<bool>(k+1, false));
    vector<vector<int>> seat_cost(k+1, vector<int>(k+1, 0));
    for(int r = 1; r <= k; r++){
        for(int s = 1; s <= k; s++){
            seat_cost[r][s] = abs(r-center) + abs(s-center);
        }
    }
    while(n--){
        int m;
        cin>>m;
        long long best_sum = LLONG_MAX;
        int best_row = -1;
        int best_l = -1;
        for(int row = 1; row <= k; row++){
            for(int l = 1; l+m-1 <= k; l++){
                int r = l+m-1;
                bool possible = true;
                long long current_sum = 0;
                for(int seat = l; seat <= r; seat++){
                    if(occupied[row][seat]){
                        possible = false;
                        break;
                    }
                    current_sum += seat_cost[row][seat];
                }
                if(possible && current_sum < best_sum){
                    best_sum = current_sum;
                    best_row = row;
                    best_l = l;
                }
            }
        }
        if(best_row == -1){
            cout<<-1<<endl;
        }
        else{
            int best_r = best_l + m - 1;
            cout<<best_row<<" "<<best_l<<" "<<best_r<<endl;
            for(int seat = best_l; seat <= best_r; seat++){
                occupied[best_row][seat] = true;
            }
        }
    }
    return 0;
}