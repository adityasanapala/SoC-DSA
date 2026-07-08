#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> solve(string s) {

        vector<int> ans;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {

                string leftPart = s.substr(0, i);
                string rightPart = s.substr(i + 1);

                vector<int> left = solve(leftPart);
                vector<int> right = solve(rightPart);

                for(int x : left) {
                    for(int y : right) {

                        if(s[i] == '+')
                            ans.push_back(x + y);

                        else if(s[i] == '-')
                            ans.push_back(x - y);

                        else
                            ans.push_back(x * y);
                    }
                }
            }
        }

        // base case
        if(ans.size() == 0) {
            ans.push_back(stoi(s));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};

int main() {

    string expression;
    cin >> expression;

    Solution obj;

    vector<int> ans = obj.diffWaysToCompute(expression);

    cout << "[ ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << "]";

    return 0;
}