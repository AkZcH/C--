#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int f(vector<int>& piles, int rate){
        int res = 0;
        for(int i=0; i<piles.size(); i++){
            res += ceil((double)piles[i] / (double)rate);
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int highest = INT_MIN;
        int lowest = 0;
        int ans = 0;
        for(int i=0; i<piles.size(); i++){
            highest = max(highest, piles[i]);
        }

        while(lowest <= highest){
            int mid = lowest + (highest - lowest)/2;
            ans = f(piles, mid);

            if(ans <= h){
                highest = mid - 1;
            }
            else{
                lowest = mid + 1;
            }
        }

        return lowest;
    }
};