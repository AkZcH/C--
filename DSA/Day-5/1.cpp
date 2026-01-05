#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    //Calculate the subsequence length
        int count = 0;
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;

        for(int i=1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        count = dp[m][n];        

        return count;
}

int main(){
    string text1 = "horse";
    string text2 = "ros";

    cout<<longestCommonSubsequence(text1, text2)<<endl;
    return 0;
}