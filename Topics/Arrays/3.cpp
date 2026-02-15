// You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0. // Return the length of such a subarray. If no such subarray exists, return 0.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxLen(vector<int>& arr) {
      unordered_map<int, int> subArraySum;
        int n = arr.size();
        int maxLen = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                maxLen = max(maxLen, i+1);
            }
            if(subArraySum.find(sum) != subArraySum.end()){
                maxLen = max(maxLen, i - subArraySum[sum]);
            }
            if(subArraySum.find(sum) == subArraySum.end()){
            subArraySum[sum] = i;
            }
        }
        return maxLen;
}