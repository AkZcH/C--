class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="" && b=="") return "";
        string s = "";
        int carry = 0;
        

        int fp = a.size() - 1;
        int sp = b.size() - 1;

        while(fp>=0 || sp>=0 || carry){
            int sum = carry;
            if(fp>=0) sum += a[fp--] - '0';
            if(sp>=0) sum += b[sp--] - '0';

            s.push_back(sum%2 + '0');
            carry = sum/2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};
