class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false; // must be divisible

        map<int,int> freq;
        // Build frequency map
        for (int card : hand) {
            freq[card]++;
        }

        // Process groups
        while (!freq.empty()) {
            int start = freq.begin()->first; // smallest card

            // Try to build group [start, start+1, ..., start+groupSize-1]
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (freq.find(card) == freq.end()) {
                    return false; // missing card
                }
                freq[card]--;
                if (freq[card] == 0) {
                    freq.erase(card); // remove exhausted card
                }
            }
        }

        return true;
    }
};
