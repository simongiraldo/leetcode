#include <string>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSize = 0;

        int i = s.size()-1;
        while (i >= 0) {
            if (s[i] == ' ' && lastSize > 0)
                return lastSize;

            if (s[i] != ' ')
                lastSize++;

            i--;
        }

        return lastSize;
    }
};