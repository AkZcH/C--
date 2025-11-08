class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> series;
        series.push_back(1);

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for(int i=1; i<n; i++){
            int element = min(series[i2]*2, min(series[i3]*3, series[i5]*5));
            series.push_back(element);
            if(element == series[i2]*2) i2++;
            if(element == series[i3]*3) i3++;
            if(element == series[i5]*5) i5++;
        }

        return series[n-1];
    }
};
