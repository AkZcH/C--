class Solution {
public:

    string rotate(string s){
        int n = s.size();

        char temp = s[0];
        for(int i=0; i<n-1; i++){
            s[i]=s[i+1];
        }
        s[n-1]=temp;

        return s;
    }

    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;

        for(int i=0; i<s.size(); i++){
            if(s==goal) return true;
            s=rotate(s);
        }

        return false;
    }
};
