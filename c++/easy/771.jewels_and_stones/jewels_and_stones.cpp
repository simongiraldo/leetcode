
#include <string>
#include <unordered_map>

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if(stones.size() == 0) return 0;

        unordered_map<char, bool> jewelsUnique;

        for(int i = 0; i < jewels.size(); i++) {
            if(jewelsUnique.find(jewels[i]) == jewelsUnique.end()) {
                jewelsUnique[jewels[i]] = true;
            }
        }

        int count = 0;

        for(int i = 0; i < stones.size(); i++) {
            if(jewelsUnique.find(stones[i]) != jewelsUnique.end()) {
                count++;
            }
        }

        return count;
    }
};