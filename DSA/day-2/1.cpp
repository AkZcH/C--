// Floor and Ceil in Sorted Array
// Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std; 

    int getFloor(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1; 
        int ans = -1;
        if(low>high) return -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= x){
                low = mid + 1;
                ans = nums[mid];
            }
            else{
                high = mid - 1; 
            }
        }
        return ans;
    }

    int getCeiling(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1; 
        if(low>high) return -1;
        int ans = -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= x){
            
                high = mid - 1; 
                ans = nums[mid];
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        return {getFloor(nums, x), getCeiling(nums, x)};
    }