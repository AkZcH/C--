// Upper Bound
// Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
// The upper bound of x is defined as the smallest index i such that nums[i] > x.
// If no such index is found, return the size of the array.

//Solution:Opposite logic of the lower bound

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= x) low = mid+1;
            else high = mid - 1;
        }

        return low;
}