class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0;

        for(int i=0; i<rows; i++) if(grid[i][0] == 1){
            q.push({i, 0});
            grid[i][0] = -1;
        }
        for(int i=0; i<rows; i++) if(grid[i][cols-1] == 1){
            q.push({i, cols-1});
            grid[i][cols-1] = -1;
        }
        for(int i=0; i<cols; i++) if(grid[0][i] == 1){
            q.push({0, i});
            grid[0][i] = -1;
        }
        for(int i=0; i<cols; i++) if(grid[rows-1][i] == 1){
            q.push({rows-1, i});
            grid[rows-1][i] = -1;
        }

        vector<int> mr = {-1, 1, 0, 0};
        vector<int> mc = {0, 0, -1, 1};

        while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nr = r + mr[d];
                    int nc = c + mc[d];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] == 1){
                        grid[nr][nc] = -1;
                        q.push({nr, nc});
                    }
                }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1) ans++;
                else if(grid[i][j]==-1) grid[i][j] = 1;
            }
        }

        return ans; 
    }
};
