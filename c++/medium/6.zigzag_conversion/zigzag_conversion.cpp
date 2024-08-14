#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;

        string conversion = s;
        int index = 0;

        int firstJump = ((numRows-1)*2)-2;
        int secondJump = 2;

        int row = 1;
        while(row <= numRows) {
            if(row == 1 || row == numRows) {
                int i = row-1;
                while(i < s.size()) {
                    conversion[index++] = s[i];
                    i += (numRows-1)*2;
                }
            } 
            else {
                int i = row-1;
                int toSum = 0;
                while(i < s.size()) {
                    conversion[index++] = s[i];
                    toSum = (toSum == firstJump) ? secondJump : firstJump;
                    i += toSum;
                }
                firstJump -= 2;
                secondJump += 2;
            }

            row++;
        }

        return conversion;
    }
}; 