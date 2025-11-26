class Solution {
public:

    int min(int a, int b){
        return a<b ? a:b;
     }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> DP(row, vector<int>(col, 0));

        DP[0][0] = grid[0][0];

        for(int i=1; i<row; i++){
            DP[i][0] = DP[i-1][0] + grid[i][0];
        }

        for(int j=1; j<col; j++){
            DP[0][j] = DP[0][j-1] + grid[0][j];
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
            }
        }

        return DP[row-1][col-1];
    }
};
