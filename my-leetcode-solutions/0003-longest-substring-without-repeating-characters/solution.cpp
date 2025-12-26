class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int bestStart = 0;
        int bestLen = 0;

        vector<int> dict(256, -1);

        for(int i=0; i<n; i++){
            if(dict[s[i]] >= start){
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;

            int windowLen = i - start + 1;
            if(windowLen > bestLen) bestLen = windowLen;
        }

        return bestLen;
    }
};
