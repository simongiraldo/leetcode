#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsString;
        for (int num : nums) {
            numsString.push_back(to_string(num));
        }

        sort(numsString.begin(), numsString.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        if (numsString[0] == "0") return "0";

        string largest;
        for (const string &num : numsString) {
            largest += num;
        }

        return largest;
    }
};