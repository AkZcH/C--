class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int time = INT_MIN;
        int n = intervals.size();

        vector<vector<int>> newIntervals;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        for(int i=0; i<n; i++){
          if(intervals[i][0]<time){
            count++;
          }
          else{
            time = intervals[i][1];
          }
        }

        return count;
    }
};
