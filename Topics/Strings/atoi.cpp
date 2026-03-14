#include<iostream>
#include<climits>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int result = 0;
        int sign = 1;
        int i=0;

        while(i<n && s[i] == ' ') i++;

        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i]=='-') sign = -1;
            else sign = 1;
            i++;
        }

        while(i<n){

            if(s[i] >= '0' && s[i] <= '9'){

                int digit = s[i] - '0';
                if((result > INT_MAX/10) || (result == INT_MAX/10 && digit>7)){
                    if(sign == 1) return INT_MAX;
                    else return INT_MIN;
                } 
                result = result*10 + digit;
            }
            else{
                break;
            }
            i++;
        }

        return result*sign;
    }
};