// 583. Delete Operation for Two Strings. Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either string.

#include<iostream>
#include<vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j = 0; j<=n; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
}

int minDistance(string word1, string word2) {
        int a = word1.size();
        int b = word2.size();

        return a + b - 2*(longestCommonSubsequence(word1, word2));
}