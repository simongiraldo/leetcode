#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1) return citations[0] == 0 ? 0 : 1;

        sort(citations.begin(), citations.end());

        int hIndex = citations.size();

        for (int i = 0; i < citations.size(); i++) {
            if(citations[i] < hIndex) {
                hIndex--;
            }
        }

        return hIndex;
    }
};