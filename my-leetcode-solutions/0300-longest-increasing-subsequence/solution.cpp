class Solution {
public:
    int f(vector<int>& num, int index, int prev, int n, vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][prev+1] != -1) return dp[index][prev+1];

        int length = 0 + f(num, index+1, prev,n, dp);
        if(prev == -1 || num[index]>num[prev]) {
            length = max(length, 1 + f(num, index+1, index, n, dp));
        }
        return dp[index][prev+1] = length;
    }
        

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(nums, 0, -1, nums.size(),dp);
    }
};
