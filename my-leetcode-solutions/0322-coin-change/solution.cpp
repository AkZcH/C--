class Solution {
public:
    int f(int index, int amount, vector<int>& nums){
        int n = nums.size();
        vector<int> prev(amount+1, 1e9);
        vector<int> curr(amount+1, 1e9);

        prev[0]=curr[0]=0;
        for(int j=1; j<=amount; j++){
            if(nums[0]<=j && j%nums[0]==0) prev[j]=j/nums[0];
        }

        for(int i=1; i<n;i++){
            for(int j=1; j<=amount; j++){
                int notTake = prev[j];

                int Take = 1e9;
                if(nums[i]<=j){
                    Take = 1 + curr[j-nums[i]];
                } 
                curr[j]= min(Take, notTake);
            }
            prev=curr;
        }

        return prev[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        // for(int i=0; i<n; i++) dp[i][0] = 0;
        // for(int j=1; j<=amount; j++){
        //     if(coins[0]<=j && j%coins[0]==0) dp[0][j]= j/coins[0];
        // }

        // for(int i=1; i<n;i++){
        //     for(int j=1; j<=amount; j++){
        //         int notTake = dp[i-1][j];

        //         int Take = 1e9;
        //         if(coins[i]<=j){
        //             Take = 1 + dp[i][j-coins[i]];
        //         } 
        //         dp[i][j]= min(Take, notTake);
        //     }
        // }

        int ans = f(n, amount, coins);
        return ans >= 1e9 ? -1 : ans;

        // return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    }
};
