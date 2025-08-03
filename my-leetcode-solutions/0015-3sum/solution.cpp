class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, k;
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i++){

            if(i !=0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=nums.size() - 1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

            if(sum>0){
                k--;
            }

            else if(sum<0){
                j++;
            }

            else{

                vector<int> ls = {nums[i], nums[j], nums[k]};
                result.push_back(ls);
                j++;
                k--;

                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;



            }
            }
            
        }

        return result;
    }
};
