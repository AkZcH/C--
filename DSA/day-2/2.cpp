// Maximum Product Subarray in an Array
// Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray. A subarray is a contiguous non-empty sequence of elements within an array.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;

        for(int i=0; i<n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *=  nums[i];
            suffix *= nums[n-i-1];

            maxProduct = max(maxProduct, max(prefix, suffix));
        }

        return maxProduct;
    }