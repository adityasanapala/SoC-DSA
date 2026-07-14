#include<bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int count_factors(int num, int factor){
    if(num == 0) return INF;
    int count = 0;
    while(num % factor == 0){
        count++;
        num /= factor;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> dp2(n, vector<int>(n));
    vector<vector<int>> dp5(n, vector<int>(n));
    int zero_r = -1;
    int zero_c = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 0){
                zero_c = j;
                zero_r = i;
            }
            dp2[i][j] = count_factors(matrix[i][j], 2);
            dp5[i][j] = count_factors(matrix[i][j], 5);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            int top2 = (i > 0) ? dp2[i-1][j] : INF;
            int left2 = (j > 0) ? dp2[i][j-1] : INF;
            dp2[i][j] += min(top2, left2);
            int top5 = (i > 0) ? dp5[i-1][j] : INF;
            int left5 = (j > 0) ? dp5[i][j-1] : INF;
            dp5[i][j] += min(top5, left5);
        }
    }
    int ans2 = dp2[n-1][n-1];
    int ans5 = dp5[n-1][n-1];
    int best_ans = min(ans2, ans5);
    if(best_ans > 1 && zero_r != -1){
        cout<<1<<endl;
        for(int i = 0; i < zero_r; i++) cout<<"D";
        for(int j = 0; j < zero_c; j++) cout<<"R";
        for(int i = zero_r; i < n-1; i++) cout<<"D";
        for(int j = zero_c; j < n-1; j++) cout<<"R";
        cout<<endl;
        return 0;
    }
    cout<<best_ans<<endl;
    vector<vector<int>>& dp = (ans2 < ans5) ? dp2 : dp5;
    string path = "";
    int r = n-1, c = n-1;
    while(r > 0 || c > 0){
        if(r == 0){
            path += "R";
            c--;
        }
        else if(c == 0){
            path += "D";
            r--;
        }
        else{
            if(dp[r-1][c] < dp[r][c-1]){
                path += "D";
                r--;
            }else{
                path += "R";
                c--;
            }
        }
    }
    reverse(path.begin(), path.end());
    cout<<path<<endl;
    return 0;
}