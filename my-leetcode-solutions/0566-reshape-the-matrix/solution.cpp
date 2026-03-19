class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c) return mat;

        vector<vector<int>> ans(r, vector<int> (c, INT_MIN));

        int curr_row=0;
        int curr_col=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[curr_row][curr_col] = mat[i][j];
                curr_col++;
                if(curr_col == c){
                    curr_col = 0;
                    curr_row++;
                }
            }
        }

        return ans;
    }
};
