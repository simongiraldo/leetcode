#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];

        string prefix;
        string compare = strs[0];
        int i = 0;
        int j = 1;
        
        while(i < compare.size()){
            while(j < strs.size()){
                if(strs[j].size() <= i || strs[j][i] != compare[i]) {
                    return prefix;
                }
                j++;
            }

            j = 1;
            prefix += compare[i];
            i++;
        }

        return prefix;
    }
};