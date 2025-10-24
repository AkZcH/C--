class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // Track last index of each character
        int maxLength = 0;
        int start = 0; // Start of current window
        
        for (int end = 0; end < s.size(); end++) {
            // If character is found in current window, move start
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            lastSeen[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
