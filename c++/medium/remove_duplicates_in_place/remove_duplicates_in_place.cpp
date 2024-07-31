#include <map>
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int k = 0;

        map<int, int> duplicates;

        for(int i = 0; i < nums.size(); i++) {
            if(duplicates.find(nums[i]) != duplicates.end()) {
                duplicates[nums[i]]++;
            } else {
                duplicates[nums[i]] = 1;
            }
        }

        int index = 0;

        for(const auto& pair : duplicates) {
            int count = 0;
            while(pair.second > count && count < 2) {
                nums[index++] = pair.first;
                count++;
            }
        }

        return index;
    }
};