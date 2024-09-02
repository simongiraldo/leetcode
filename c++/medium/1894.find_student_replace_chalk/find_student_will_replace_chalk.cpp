#include <vector>

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if(chalk.size() <= 1) return 0;

        int index = -1;
        
        while(k >= 0) {
            index = (index == chalk.size()-1) ? 0 : index+1;
            k -= chalk[index];
        }

        return index;
    }
};