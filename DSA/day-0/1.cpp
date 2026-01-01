// wap to find the longest subArray with equal 0's and 1's

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxLen(vector<int> &nums){
    unordered_map<int, int> mp;
    int n = nums.size();
    int sum = 0;
    int maxLen = 0;

    mp[0] = -1;

    for(int i=0; i<n; i++){
        sum += (nums[i]==0 ? -1:1 );

        if(sum == 0){
            maxLen = i+1;
        }

        if(mp.find(sum) != mp.end()){
            maxLen = max(maxLen, i - mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main(){
    vector<int>  arr = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout<<maxLen(arr);

    return 0;
}