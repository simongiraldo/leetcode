#include <vector>

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int asciiCodeForSix = 54;
        int asciiCodeForZero = 48;

        for(int i = 0; i < details.size(); i++) {
            if(details[i][11] > asciiCodeForSix || (details[i][11] == asciiCodeForSix && details[i][12] > asciiCodeForZero)) {
                count++;
            }
        }

        return count;
    }
};