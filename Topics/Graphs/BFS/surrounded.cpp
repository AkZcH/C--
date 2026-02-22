#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        int nO = 0;

        for(int i=0; i<rows; i++) if(board[i][0] == 'O'){
            q.push({i, 0});
            board[i][0] = 'T';
        }
        for(int i=0; i<rows; i++) if(board[i][cols-1] == 'O'){
            q.push({i, cols-1});
            board[i][cols-1] = 'T';
        }
        for(int i=0; i<cols; i++) if(board[0][i] == 'O'){
            q.push({0, i});
            board[0][i] = 'T';
        }
        for(int i=0; i<cols; i++) if(board[rows-1][i] == 'O'){
            q.push({rows-1, i});
            board[rows-1][i] = 'T';
        }

        vector<int> mr = {-1, 1, 0, 0};
        vector<int> mc = {0, 0, -1, 1};

        while(!q.empty()){

            int size = q.size();

            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nr = r + mr[d];
                    int nc = c + mc[d];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && board[nr][nc] == 'O'){
                        board[nr][nc] = 'T';
                        q.push({nr, nc});
                    }
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};