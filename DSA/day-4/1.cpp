// 1312. Minimum Insertion Steps to Make a String Palindrome
// Given a string s. In one step you can insert any character at any index of the string.Return the minimum number of steps to make s palindrome.A Palindrome String is one that reads the same backward as well as forward.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0) dp[i][j] = 0;

                else if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return n - dp[n][n];
}

int main(){
    string s = "level";
    cout<<minInsertions(s);
    return 0;

}