#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    int f(int i, int j, vector<int>& nums){
        if(i == j) return 0;
        int mini = INT_MAX;
        int steps = 0;
        for(int k=i; k<=j-1; k++){
            steps = nums[i-1]*nums[k]*nums[j] + f(i,k, nums) + f(k+1,j,  nums);
            mini = min(mini, steps);
        }
        return mini;
    }

	int matrixMultiplication(vector<int>& nums){
        return f(1, nums.size()-1, nums);
    }


// Tabulation
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        int steps = 0;
        for(int k=i; k<=j-1; k++){
            steps = nums[i-1]*nums[k]*nums[j] + f(i,k, nums) + f(k+1,j,  nums);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

	int matrixMultiplication(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        f(1, nums.size()-1, nums, dp);
        return dp[1][n-1];
    }