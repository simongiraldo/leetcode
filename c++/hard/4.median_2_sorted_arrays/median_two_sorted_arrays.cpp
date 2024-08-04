#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) return 0.0;

        vector<int> mergedSorted(nums1.size() + nums2.size());

        int index1 = 0;
        int index2 = 0;

        int indexMerged = 0;
        while(index1 < nums1.size() && index2 < nums2.size()) {
            if(nums1[index1] < nums2[index2]) {
                mergedSorted[indexMerged++] = nums1[index1++];
            } else {
                mergedSorted[indexMerged++] = nums2[index2++];
            }
        }

        while(index1 < nums1.size()) mergedSorted[indexMerged++] = nums1[index1++];

        while(index2 < nums2.size()) mergedSorted[indexMerged++] = nums2[index2++];


        int indexMedian = (nums1.size() + nums2.size()) / 2;
        if(mergedSorted.size() % 2 == 0) {
            return static_cast<double>(mergedSorted[indexMedian-1] + mergedSorted[indexMedian]) / 2;
        }

        return static_cast<double>(mergedSorted[indexMedian]);
    }
};