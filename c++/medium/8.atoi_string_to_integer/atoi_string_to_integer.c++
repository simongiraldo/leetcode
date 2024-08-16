#include <string>

class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;

        int whiteSpaces = 0;
        while(whiteSpaces < s.size() && s[whiteSpaces] == ' ') whiteSpaces++;

        bool isNegative = false;
        if(s[whiteSpaces] == '-') {
            isNegative = true;
            whiteSpaces++;
        } else if(s[whiteSpaces] == '+') {
            whiteSpaces++;
        }

        int zeros = whiteSpaces;
        while(zeros < s.size() && s[zeros] == '0') zeros++;

        int charIndex = zeros;
        while(charIndex < s.size() && s[charIndex] >= '0' && s[charIndex] <= '9') charIndex++;

        int multiplier = charIndex - zeros;
        if(multiplier > 10) return isNegative? INT_MIN : INT_MAX;
        if(multiplier > 1) multiplier = pow(10, (multiplier-1));

        int max = INT_MAX;
        int min = INT_MIN;
        int result = 0;

        bool isCrashing = multiplier > 10;
        int digits = zeros;
        while(digits < s.size()) {
            if(s[digits] < '0' || s[digits] > '9') {
                return result;
            }

            int num = s[digits] - 48;

            if(isCrashing) {
                if (isNegative) {
                    if(-num < (min / multiplier)) return INT_MIN;
                    if(-num != (min / multiplier)) isCrashing = false;
                } else {
                    if(num > (max / multiplier)) return INT_MAX;
                    if(num != (max / multiplier)) isCrashing = false;
                }
            }

            if (isNegative) {
                result -= num * multiplier;
                min += multiplier != 1 ? (-(min/multiplier)) * multiplier : 0;
            } else {
                result += num * multiplier;
                max -= (max/multiplier) * multiplier;
            }

            multiplier /= 10;
            digits++;
        }

        return result;
    }
};