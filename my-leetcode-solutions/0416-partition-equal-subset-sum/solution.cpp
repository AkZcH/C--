class Solution {
public:

     int f(vector<int>& arr, int target, int index, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(index == 0) return (arr[0] == target);

        if(dp[index][target] != -1) return dp[index][target];

        int notTake = f(arr, target, index-1, dp);
        int take = 0;
        if(arr[index] <= target) take = f(arr, target-arr[index], index-1, dp);

        return dp[index][target] = take || notTake;
    }

    bool isSum(vector<int>& arr, int target){
        bool isSubSetSum = false;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        isSubSetSum = f(arr, target, n-1, dp) == 1 ? true:false;
        return isSubSetSum;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2== 1) return false;
        int target=sum/2;

        return isSum(nums, target);
    }
};
