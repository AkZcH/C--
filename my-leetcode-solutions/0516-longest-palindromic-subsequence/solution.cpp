class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string original = s;
        string rev(s.rbegin(), s.rend());
        int m = s.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i=1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                if(original[i-1] == rev[j-1]) curr[j] = prev[j-1] + 1;
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};
