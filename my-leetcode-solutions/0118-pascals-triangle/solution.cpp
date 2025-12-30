class Solution {
public:
    vector<int> genRows(int row){
        vector<int> rowVector;
        int x = 1;
        rowVector.push_back(x);
        for(int i=1; i<=row; i++){
            x = x * (row - i + 1);
            x = x/i;
            rowVector.push_back(x);
        }
        return rowVector;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i=0; i<numRows; i++){
            result.push_back(genRows(i));
        }

        return result;
    }
};
