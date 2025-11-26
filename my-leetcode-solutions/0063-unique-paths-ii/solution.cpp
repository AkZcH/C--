class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> DP(m, vector<int>(n));

        if (obstacleGrid[0][0] == 1) 
            return 0;
        DP[0][0] = 1;

        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0]==1) DP[i][0]=0;
            else DP[i][0] = DP[i-1][0];
        }

        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j]==1) DP[0][j]=0;
            else DP[0][j] = DP[0][j-1];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                   if(obstacleGrid[i][j]==1) DP[i][j]==0;
                   else{
                        DP[i][j] = DP[i-1][j] + DP[i][j-1];
                   }
            }
        }

        return DP[m-1][n-1];
    }
};
