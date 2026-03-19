class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // int land = 0;
        int perimeter = 0;
        // queue<pair<int, int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    perimeter += 4;

                    if(i>0 && grid[i-1][j] == 1) perimeter -= 2;
                    if(j>0 && grid[i][j-1] == 1) perimeter -= 2;
                    // q.push({i, j});
                }
            }
        }

        // vector<int> mr = {-1, 1, 0, 0};
        // vector<int> mc = {0, 0, -1, 1};
        // if(land == 0) return perimeter;

        // while(!q.empty()){
        //     auto[r, c] = q.front();
        //     perimeter += 4;
        //     q.pop();

        //     for(int d=0; d<4; d++){
        //         int nr = r + mr[d];
        //         int nc = c + mc[d];

        //         if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] == 1){
        //             perimeter -= 1;
        //         }
        //     }
        // }

        return perimeter;
    }
};
