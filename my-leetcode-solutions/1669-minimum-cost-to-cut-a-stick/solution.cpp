class Solution {
public:
    int f(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        int mini = INT_MAX;
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int index = i; index<=j; index++){
            int cost = cuts[j+1] - cuts[i-1] + f(cuts, i, index-1, dp) + f(cuts, index+1,j, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
                int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(size+1, vector<int>(size+1, -1));
        return f(cuts,1, size, dp);
    }
};
