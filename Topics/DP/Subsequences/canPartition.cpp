#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum%2 != 0) return false;
    int target = sum/2;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
    if(target>=arr[0]) dp[0][arr[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=target; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j >= arr[i]) take = dp[i-1][j - arr[i]];
            dp[i][j] = notTake || take;
        }
    }
    return dp[n-1][target];
}