class Solution {
public:


    string convertToTitle(int columnNumber) {
        if(columnNumber==0) return "";

        columnNumber--;
            char column = 'A' + (columnNumber%26);

        return convertToTitle(columnNumber/26) + column;
    }
};
