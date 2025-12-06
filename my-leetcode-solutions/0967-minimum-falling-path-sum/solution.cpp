class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> DP(n, vector<int>(n, 0));

        for(int j =0; j<n; j++){
            DP[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int best = DP[i-1][j];

                if(j>0){
                    best = min(best, DP[i-1][j-1]);
                }

                if(j<n-1){
                    best = min(best, DP[i-1][j+1]);
                }

                DP[i][j] = matrix[i][j] + best;
            }
        }
        int min=INT_MAX;

        for(int j=0; j<n; j++){
            if(DP[n-1][j]<min) min = DP[n-1][j];
        }

        return min;
        }
};
