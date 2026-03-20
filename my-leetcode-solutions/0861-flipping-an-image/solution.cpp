class Solution {
public:
    vector<int> reverseRow(vector<int> row){
        int n = row.size();
        int i = 0;
        while(i< (n+1)/2){
            int left = row[i];
            int right = row[n-1-i];

            row[i] = right ^ 1;
            row[n-i-1] = left ^ 1;

            i++;
        }
        return row;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        for(int i=0; i<rows; i++){
            image[i] = reverseRow(image[i]);
        }
        return image;
    }
};
