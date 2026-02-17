#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void floodFill(vector<vector<char>>& grid, queue<pair<int, int>>& q){
        auto [i, j] = q.front();
        q.pop();
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> mr = {-1, 1, 0, 0};
        vector<int> mc = {0, 0, -1, 1};

        for(int d=0; d<4; d++){
            int nr = i + mr[d];
            int nc = j + mc[d];

            if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] == '1'){
                q.push({nr, nc});
                grid[nr][nc] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        floodFill(grid, q);
                    }
                }
            }
        }

        return islands;
    }
};