#include <unordered_set>

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> valid;

        for(int i = 0; i < allowed.size(); i++) {
            valid.insert(allowed[i]);
        }

        int wordIndex = 0;
        bool consistent = true;
        int count = 0;

        for(int i = 0; i < words.size(); i++) {
            while(wordIndex < words[i].size()) {
                if(valid.find(words[i][wordIndex]) == valid.end()) {
                    consistent = false;
                    break;
                }

                wordIndex++;
            }

            if(consistent) {
                count++;
            }

            wordIndex = 0;
            consistent = true;
        }

        return count;
    }
};