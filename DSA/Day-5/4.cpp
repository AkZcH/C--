//115. Distinct Subsequences. Given two strings s and t, return the number of distinct subsequences of s which equals t.The test cases are generated so that the answer fits on a 32-bit signed integer.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<double> arr(n+1, 0);
        arr[0] = 1;

        for(int i=1; i<=m; i++){
            for(int j=n; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    arr[j] = arr[j] + arr[j-1];
                }
            }
        }

        return (int)arr[n];
        
}