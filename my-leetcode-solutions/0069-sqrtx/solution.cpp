class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        long long low = 0;
        long long high = x;
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high - low)/2;
            long long sq = mid * mid;

            if(sq == x) return mid;       
            else if(sq < x){
                ans = mid;                // mid is a candidate
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        return ans;
    }
};

