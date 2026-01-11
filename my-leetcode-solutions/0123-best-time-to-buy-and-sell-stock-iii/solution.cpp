class Solution {
public:
    int f(vector<int>& price, int index, int buy, int cap, vector<vector<vector<int>>>& dp){
        if(index==price.size() || cap==0) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if(buy){
            return dp[index][buy][cap] = max(-price[index] + f(price, index+1, 0, cap, dp), f(price, index+1, 1, cap, dp));
        }
        else{
            return dp[index][buy][cap] = max(price[index] + f(price, index+1, 1, cap-1,dp), f(price, index+1, 0, cap, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, 
            vector<vector<int>>(2, vector<int>(3, -1)));

        return f(prices, 0, 1, 2, dp);
    }
};
