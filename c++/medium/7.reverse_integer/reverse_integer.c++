#include <stack>
#include <unordered_map>

class Solution {
public:
    int reverse(int x) {
        if (x < 10 && x > -10)
            return x;

        stack<int> st;

        bool isNegative = x < 0;

        unordered_map<int, int> limits = {
            {1000000000, 2}, {100000000, 1},
            {10000000, 4},   {1000000, 7},
            {100000, 4},     {10000, 8},
            {1000, 3},       {100, 6},
            {10, 4},         {1, isNegative ? 8 : 7}};

        int maxValue = 0;
        if (x >= 1000000000 || x <= -1000000000) {
            maxValue = 1000000000;
        } else if (x >= 100000000 || x <= -100000000) {
            maxValue = 100000000;
        } else if (x >= 10000000 || x <= -10000000) {
            maxValue = 10000000;
        } else if (x >= 1000000 || x <= -1000000) {
            maxValue = 1000000;
        } else if (x >= 100000 || x <= -100000) {
            maxValue = 100000;
        } else if (x >= 10000 || x <= -10000) {
            maxValue = 10000;
        } else if (x >= 1000 || x <= -1000) {
            maxValue = 1000;
        } else if (x >= 100 || x <= -100) {
            maxValue = 100;
        } else if (x >= 10 || x <= -10) {
            maxValue = 10;
        }

        int divider = maxValue;

        while (divider > 0) {
            int digit = x / divider;

            if(isNegative) {
                digit *= -1;
                x += digit * divider;
            } else {
                x -= digit * divider;
            }

            st.push(digit);
            divider /= 10;
        }

        bool isCrashing = maxValue == 1000000000;
        int reversed = 0;
        while (!st.empty()) {
            if (isCrashing) {
                if (st.top() > limits[maxValue]) {
                    return 0;
                }

                if (st.top() < limits[maxValue]) isCrashing = false;
            }

            if(isNegative) {
                reversed -= st.top() * maxValue;
            } else {
                reversed += st.top() * maxValue;
            }
            st.pop();
            maxValue /= 10;
        }

        return reversed;
    }
};