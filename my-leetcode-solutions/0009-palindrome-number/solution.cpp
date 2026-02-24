class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int original = x;
        int reversed = 0;

        if(x % 10 == 0 && x != 0) return false;

        while(x>reversed){
            reversed = (reversed*10) + x%10;
            x/=10;
        }

        return (reversed == x || x == reversed/10);

    }
};
