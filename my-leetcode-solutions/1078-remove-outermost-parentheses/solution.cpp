class Solution {
public:


    string removeOuterParentheses(string s) {
        string result="";
        int counter=1;
        int n = s.length();
        int start=0;
        for(int i=start+1; i<n; i++){
            if(s[i]=='('){
                counter++;
            }
            else{
                counter--;
            }
            if(counter==0){
                result += s.substr(start+1, i-start-1);
                start=i+1;

            }
        }

            return result;

    }

};
