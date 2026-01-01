// Lower Bound
// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.

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