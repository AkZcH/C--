class Solution {
public:

    long long hours(vector<int>& piles, int h){
        long long sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += ceil(double(piles[i])/double(h));
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high= *max_element(piles.begin(), piles.end());
        long long k=0;
        
        while(low<=high){
            long long mid = low + (high-low)/2;

            long long n = hours(piles, mid);
            if(n<=h){
                k=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return k;

    }
};
