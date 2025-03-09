#include <vector>

using namespace std;

class Solution {
private:
    int getCircularIndex(int index, int size) {
        if(index < size) {
            return index;
        }

        return abs(size - index);
    }
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int left = 0;
        int right = 1;
        int totalAlternating = 0;
        int lastColor = colors[left];
        int n = colors.size();
        
        while(left < n) {
            if(lastColor == colors[right]) {
                if(left > right) {
                    break;
                }
                left = right;
                right = this->getCircularIndex(right+1, n);
                continue;
            }

            int tiles = right - left + 1;
            if(left > right) {
                tiles = n - left + right + 1;
            }

            if(tiles == k) {
                totalAlternating++;
                left++;
            }

            lastColor = colors[right];
            right = this->getCircularIndex(right+1, n);
        }

        return totalAlternating;
    }
};