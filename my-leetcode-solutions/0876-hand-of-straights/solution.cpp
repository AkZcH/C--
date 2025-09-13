class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size()%groupSize) != 0) return false;


        unordered_map<int, int> count;
        for(int card : hand) count[card]++;     

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &p : count) {
            minHeap.push(p.first);
        }
       
        while (!minHeap.empty()) {
            int first = minHeap.top(); // smallest available card
            for (int i = 0; i < groupSize; i++) {
                int card = first + i;
                if (count.find(card) == count.end()) 
                    return false; // missing consecutive card

                count[card]--;
                if (count[card] == 0) {
                    count.erase(card);
                    if (!minHeap.empty() && minHeap.top() == card)
                        minHeap.pop(); // remove used card from heap
                }
            }
        }

        return true;

        
    }
};
