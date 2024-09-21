#include <vector>

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        map<string, int>lexical;

        for(int i = 1; i <= n; i++) {
            lexical[to_string(i)] = i;
        }

        for(const auto& pair : lexical) {
            nums.push_back(pair.second);
        }

        return nums;
    }
};