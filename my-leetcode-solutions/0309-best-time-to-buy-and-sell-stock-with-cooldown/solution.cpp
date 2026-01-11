class Solution {
public:
            int f(vector<int>& price, int index, int buy, vector<vector<int>>& dp){
        if(index>=price.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            return dp[index][buy] = max(-price[index] + f(price, index+1, 0, dp), f(price, index+1, 1, dp));
        }
        else{
            return dp[index][buy] = max(price[index] + f(price, index+2, 1,dp), f(price, index+1, 0, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, dp);
    }
};
