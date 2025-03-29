#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = 0;
        int secondDominant = 0;
        int domCount = 0;
        int secondDomCount = 0;
        unordered_map<int, int> elementCount;

        for(int i = 0; i < nums.size(); i++) {
            if(elementCount.find(nums[i]) == elementCount.end()) {
                elementCount[nums[i]] = 1;
            } else {
                elementCount[nums[i]]++;
            }
        }
        
        for(const auto& pair : elementCount) {
            if(pair.second > domCount) {
                secondDominant = dominant;
                secondDomCount = domCount;
                dominant = pair.first;
                domCount = pair.second;
            } else if(pair.second > secondDomCount) {
                secondDominant = pair.first;
                secondDomCount = pair.second;
            }
        }
        
        domCount = 0;
        secondDomCount = 0;
        int i = 0;
        while(i < nums.size()) {
            domCount += nums[i] == dominant;
            secondDomCount += nums[i] == secondDominant;

            int minRightDominants = (nums.size()-(i+1))/2 + 1;
            int minLeftDominants = (i+1)/2 + 1;

            if(domCount > secondDomCount && domCount >= minLeftDominants
            && elementCount[dominant]-domCount >= minRightDominants){
                return i;
            }

            i++;
        }

        return -1;
    }
};