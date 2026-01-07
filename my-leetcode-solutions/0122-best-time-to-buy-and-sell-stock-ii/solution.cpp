class Solution {
public:
    // long f(int index, int buy, vector<int>& prices, int n, vector<vector<int>>dp){
    //     long profit = 0;
    //     if(index==n) return 0;
    //     if(dp[index][buy] != -1) return dp[index][buy];

    //     if(buy){
    //         profit = max(-prices[index] + f(index+1, 0, prices, n,dp), 0 + f(index+1, 1, prices, n, dp));
    //     }
    //     else{
    //         profit = max(prices[index] + f(index+1, 1, prices, n, dp), 0 + f(index+1, 0, prices, n, dp));
    //     }

    //     return dp[index][buy]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long>(2, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                long profit = 0;

                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                }
                else{
                    profit = max(prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
