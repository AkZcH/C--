class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

map<char, string> phone = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};        
vector<string> res;
        string path;

        function<void(int)>backtrack = [&](int i){
            if(i == digits.size()){
                res.push_back(path);
                return;
            }
            for(char c : phone[digits[i]]){
                path.push_back(c);
                backtrack(i+1);
                path.pop_back();
            }
        };
        backtrack(0);
        return res;
    }
};
