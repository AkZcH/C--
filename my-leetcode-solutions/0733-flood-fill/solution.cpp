class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int original = image[sr][sc];
        if(original == color) return image;

        queue<pair<int, int>>q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<int> mr = {-1, 1, 0,0};
        vector<int> mc = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto[r, c] = q.front();
                q.pop();

                for(int d=0; d<4; d++){
                    int nr = r + mr[d];
                    int nc = c + mc[d];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && image[nr][nc] == original){
                        image[nr][nc] = color;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return image;
    }
};
