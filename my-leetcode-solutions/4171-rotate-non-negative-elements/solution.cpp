class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> positive;
        
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                positive.push_back(nums[i]);
            }
        }
        int m = positive.size();
        if(m==0) return nums;

        k = k%m;
        if(k==0) return nums;

        vector<int> rotated;

        for (int i = k; i <m; i++) {
            rotated.push_back(positive[i]);
        }
        for (int i = 0; i < k; i++) {
            rotated.push_back(positive[i]);
        }


        int index=0;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                nums[i] = rotated[index++];
            }
        }
        return nums;
        
    }
};
