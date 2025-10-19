class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> multiples;

        for(int num : nums){
            if(num>0 && num%k==0){
                multiples.insert(num);
            }
        } 

        int multiple = k;
        while(1){
            if(multiples.find(multiple)==multiples.end()){
                return multiple;
            }
            multiple += k;
        }


    }
};
