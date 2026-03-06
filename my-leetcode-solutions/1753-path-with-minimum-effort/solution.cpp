class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!pq.empty()){
            auto[effort, position] = pq.top();
            pq.pop();

            int row = position.first;
            int col = position.second;

            if(row == rows-1 && col == cols-1) return effort;

            for(int d=0; d<4; d++){
                int nr = row + move[d][0];
                int nc = col + move[d][1];

                if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                    int newEffort = max(effort, abs(heights[nr][nc] - heights[row][col]));

                    if(newEffort < distance[nr][nc]){
                        distance[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
