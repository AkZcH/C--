#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string& s, vector<int>& dp){
        int n = s.size();
        if(i==n) return -1;
        if(isPalindrome(i, n-1, s)) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = 1e9;

        for(int index=i; index<n; index++){
            int res=0;
            if (isPalindrome(i, index, s)){
                mini = min(mini, 1 + f(index+1, s, dp));
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};