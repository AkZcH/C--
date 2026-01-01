// 974. Subarray Sums Divisible by K
// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = ((sum % k) + k)%k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem] += 1;
        }

        return count;