class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = 0;
        int secondDominant = 0;
        vector<int> dominantCount(nums.size(), 0);
        vector<int> secondDominantCount(nums.size(), 0);
        unordered_map<int, int> elementCount;

        for(int i = 0; i < nums.size(); i++) {
            if(elementCount.find(nums[i]) == elementCount.end()) {
                elementCount[nums[i]] = 1;
            } else {
                elementCount[nums[i]]++;
            }
        }

        for(const auto& pair : elementCount) {
            if(pair.second > dominant) {
                secondDominant = dominant;
                dominant = pair.first;
            } else if(pair.second > secondDominant) {
                secondDominant = pair.second;
            }
        }

        int domCountByIndex = 0;
        int secondDominantCountByIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            domCountByIndex += nums[i] == dominant;
            secondDominantCountByIndex += nums[i] == secondDominant;

            dominantCount[i] = domCountByIndex;
            secondDominantCount[i] = secondDominantCountByIndex;
        }

        int index = 0;
        while(index < nums.size()-1) {
            if(dominantCount[index] > secondDominantCount[index]) {
                return index;
            }
            index++;
        }

        return -1;
    }
};