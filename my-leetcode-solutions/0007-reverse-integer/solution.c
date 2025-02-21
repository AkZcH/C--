#include <limits.h>

int reverse(int x){
    int digit=0;
    int reverse=0;

    while(x!=0){
        digit=x%10;

         if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && digit > 7)) {
            return 0; // Overflow case (positive limit)
        }
        if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && digit < -8)) {
            return 0; // Overflow case (negative limit)
        }
        
        reverse = (10*reverse) + digit;
        x=x/10;
    }

    return reverse;
}
