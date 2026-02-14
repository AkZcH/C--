class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>>q;
        int fresh = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;
        vector<int> mr = {-1, 1, 0, 0};
        vector<int> mc = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();
            bool rotted = false;

            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();

                for(int d=0; d<4; d++){
                    int nr = r + mr[d];
                    int nc = c + mc[d];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }

            if(rotted) minutes++;
        }

        return fresh == 0 ? minutes:-1;

    }
};
