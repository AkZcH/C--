

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int lowerBound(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] >= x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int