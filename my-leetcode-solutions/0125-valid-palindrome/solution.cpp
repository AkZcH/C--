class Solution {
public:

    bool Palindrome(int i, int j, string& s){
        if(i>=j){
            return true;
        }

        if(!isalnum(s[i])){
            return Palindrome(i+1, j, s);
        }

        if(!isalnum(s[j])){
            return Palindrome(i, j-1, s);
        }

        if(tolower(s[i]) != tolower(s[j])) return false;


        return Palindrome(i+1,j-1, s);


    }
    bool isPalindrome(string s) {
        int n = s.size();
        return Palindrome(0,n-1, s);
    }
};
