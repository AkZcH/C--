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

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;


        if(k>=n/2){
            for(int i=1; i<n; i++){
                if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1]; 
            }
            return profit;
        }

        vector<vector<vector<int>>> dp(n,
                vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, 0, 1, k, dp);
    }
};
