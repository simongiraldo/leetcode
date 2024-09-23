#include <stack>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ' && word.size() > 0) {
                st.push(word);
                word = "";
            }

            if(s[i] != ' ') word += s[i];
        }

        if(word.size() > 0) st.push(word);

        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();

            if(!st.empty()) result += ' ';
        }

        return result;
    }
};