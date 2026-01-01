#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubarray(vector<int> nums, int k){
    int n = nums.size();
    int sum = 0;
    int maxLen = 0;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        sum += nums[i];

        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        if(mp.find(sum-k) != mp.end()){
            maxLen = max(maxLen, i - mp[sum-k]);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << longestSubarray(nums, k) << endl;
    return 0;
}
