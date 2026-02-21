

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> res(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        vector<int> mr = {-1, 1, 0, 0};
        vector<int> mc = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                    int nr = r + mr[i];
                    int nc = c + mc[i]; 
            
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && res[nr][nc] == -1){
                    res[nr][nc] = res[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return res;
    }
};