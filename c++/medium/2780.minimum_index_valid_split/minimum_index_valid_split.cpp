class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = 0;
        int secondDominant = 0;
        int biggest = 0;
        int secondBiggest = 0;
        unordered_map<int, int> elementCount;

        for(int i = 0; i < nums.size(); i++) {
            if(elementCount.find(nums[i]) == elementCount.end()) {
                elementCount[nums[i]] = 1;
            } else {
                elementCount[nums[i]]++;
            }
        }

        for(const auto& pair : elementCount) {
            if(pair.second > biggest) {
                secondDominant = dominant;
                secondBiggest = biggest;
                dominant = pair.first;
                biggest = pair.second;
            } else if(pair.second > secondBiggest) {
                secondDominant = pair.first;
                secondBiggest = pair.second;
            }
        }

        int domCountByIndex = 0;
        int secondDominantCountByIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            domCountByIndex += nums[i] == dominant;
            secondDominantCountByIndex += nums[i] == secondDominant;

            int minLeftDominants = (nums.size()+1-i)/2;
            minLeftDominants = minLeftDominants == 0 ? 1 : minLeftDominants;

            int minRightDominants = (i+1)/2;
            minRightDominants = minRightDominants == 0 ? 1 : minRightDominants;

            if(domCountByIndex > secondDominantCountByIndex 
            && domCountByIndex > minRightDominants
            && elementCount[dominant]-domCountByIndex > minLeftDominants) {
                return i;
            }
        }

        return -1;
    }
};