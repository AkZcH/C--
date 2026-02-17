#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    int f(vector<int>& coins, int amount, int index, vector<vector<int>>& dp){
        if(index == 0) return (amount%coins[0]) == 0 ? amount/coins[0] : 1e9;
        if(amount == 0) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = f(coins, amount, index-1, dp);
        int take = 1e9;
        if(amount>=coins[index]){
            take = 1+ f(coins, amount - coins[index], index, dp);
        }
        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(coins, amount, n-1, dp);
        return ans == 1e9 ? -1 : ans;
    }