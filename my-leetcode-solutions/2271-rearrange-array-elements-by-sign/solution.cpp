class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        int index=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                result[index] = nums[i];
                index+=2;
            }
        }
        index=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                result[index] = nums[i];
                index+=2;
            }
        }
        return result;
    }
};
