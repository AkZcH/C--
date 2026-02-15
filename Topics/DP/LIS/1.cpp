#include<iostream>
#include<vector>
using namespace std;

int f(vector<int>& arr, int index, int prev, vector<vector<int>>& dp){
    if(index == arr.size()) return 0;
    if(dp[index][prev+1] != -1) return dp[index][prev+1];

    int length = f(arr, index+1, prev, dp);
    if(prev == -1 || arr[index] > arr[prev]){
        length = max(length, 1+f(arr, index+1, index, dp));
    }

    return dp[index][prev+1] = length;
}

int LIS(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(arr, 0, -1, dp);
}