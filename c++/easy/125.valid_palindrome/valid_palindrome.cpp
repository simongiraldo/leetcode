#include <string>

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;

        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left] == ' ' || !isalnum(s[left])) {
                left++;
                continue;
            }
            if(s[right] == ' ' || !isalnum(s[right])) {
                right--;
                continue;
            }

            if(getLowerCase(s[left]) != getLowerCase(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }

    int getLowerCase(char a) {
        if(a >= 65 && a < 97) return a+32;

        return a;
    }
};