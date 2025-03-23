#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long result = 1;
        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long divisorAbs = divisor;
        divisorAbs = abs(divisorAbs);
        long dividendAbs = dividend;
        dividendAbs = abs(dividendAbs);
        long accomulated = divisorAbs;

        if(dividendAbs < divisorAbs) return 0;

        while(accomulated+divisorAbs <= dividendAbs) {
            accomulated += divisorAbs;
            result++;
        }

        if(isNegative) {
            return -result < INT_MIN ? INT_MIN : -result;
        }

        return result > INT_MAX ? INT_MAX : result;
    }
};