class Solution {
public:

    long long mod = 1e9 + 7;

    int function(long long base, long long exp){
        int result=1;

        while(exp>0){
            if(exp%2 == 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp/2;
        }

        return result; 
    }

    int countGoodNumbers(long long n) {

        long long odd = (n+1)/2;
        long long even = n/2;

        long long evenWays = function(4, even);
        long long oddWays = function(5, odd);

        return (evenWays * oddWays) % mod;
    }
};
