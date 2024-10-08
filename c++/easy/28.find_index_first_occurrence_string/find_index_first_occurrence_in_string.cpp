#include <string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0;
        int index = 0;
        int lastStart = 0;

        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[0] && index != i && lastStart == 0) lastStart = i;

            if(haystack[i] == needle[count]) {
                count++;
            }
            else {
                if(lastStart > 0) {
                    i = lastStart-1;
                } 

                index = i+1;
                lastStart = 0;
                count = 0;
                continue;
            }

            if(count == needle.size()) {
                return i - (count-1);
            }
        }

        return -1;
    }
};