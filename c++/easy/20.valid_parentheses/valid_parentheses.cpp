#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                int openDifference = s[i] == ')' ? 1 : 2;
                if(st.empty() || st.top() != s[i]-openDifference) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};