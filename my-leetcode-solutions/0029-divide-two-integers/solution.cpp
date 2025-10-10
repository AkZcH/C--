class Solution {
public:
   int divide(int dividend, int divisor) {
    // Edge case: overflow
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    // Determine the sign of the result
    bool isNegative = (dividend < 0) != (divisor < 0);
    
    // Work with positive values
    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long)divisor);
    
    long long quotient = 0;
    
while (dvd >= dvs) {
    long long temp = dvs, multiple = 1;
    while (dvd >= (temp << 1)) {  
        temp <<= 1;
        multiple <<= 1;
    }
    dvd -= temp;          // Subtract the largest chunk
    quotient += multiple; // Add how many times we subtracted
}
    
    return isNegative ? -quotient : quotient;
}

};
