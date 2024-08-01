class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0;
        string substring;

        unordered_map<int, int> substringIndexes;
    
        for(int i = 0; s[i] != '\0'; i++) {
            if(substringIndexes.find(s[i]) != substringIndexes.end()) {
                longestLength = longestLength < substring.length() ? substring.length() : longestLength;

                if(substring[substring.length()-1] == s[i]) {
                    substring = "";
                } else {
                    int index = substringIndexes.at(s[i]) + 1;
                    substring = substring.substr(index);
                }

                substringIndexes.clear();
                for(int j = 0; j < substring.length(); j++) {
                    substringIndexes[substring[j]] = j;
                }
            }

            substring += s[i];
            substringIndexes[s[i]] = substring.length()-1;
        }

        longestLength = longestLength < substring.length() ? substring.length() : longestLength;
        return longestLength;
    }
};