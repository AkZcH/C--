class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> dict(256, -1);
        int start = 0;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            if(dict[s[i]] >= start){
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
            int len = i - start + 1;
            if(len > maxLen){
                maxLen = len;
            }
        }
        return maxLen;
    }
};
