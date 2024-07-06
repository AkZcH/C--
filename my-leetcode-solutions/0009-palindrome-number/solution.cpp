class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int ans = 0;
        int original = x;

        while (original != 0) {
            int rem = original % 10;
                       if(ans>=INT_MAX/10 || ans<=INT_MIN/10){
                return false;
            }

            original = original / 10;
            ans = ans * 10 + rem;

 
        }

        return (x == ans);
    }
};

