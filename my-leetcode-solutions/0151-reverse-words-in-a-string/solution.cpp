class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        string ans = "";
        int n = s.size();
        int l=0;
        int r=n-1;

        while(l<n && s[l]==' ') l++;
        while(r>0 && s[r]==' ') r--;

        for(int i=l; i<=r; i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                if(!word.empty()){
                      words.push_back(word);
                      word.clear();
                }
            }
        }
        if(!word.empty()) words.push_back(word);

        reverse(words.begin(), words.end());

        for(int i=0; i<words.size(); i++){
            if(i!=0){
                ans+=" ";
            }
                            ans+=words[i];

        }

         return ans;
    }
};
