// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;    

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minPrice = INT_MAX;
    int profit=0;

    for(int i = 0; i<n; i++){
        minPrice = min(prices[i], minPrice);
        profit = max(profit, prices[i] - minPrice);
    }

    return profit; 
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
}