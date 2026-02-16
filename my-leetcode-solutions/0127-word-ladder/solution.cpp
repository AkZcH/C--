class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>store(wordList.begin(), wordList.end());
        store.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();
            if(word == endWord) return steps;
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(store.find(word) != store.end()){
                        store.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
