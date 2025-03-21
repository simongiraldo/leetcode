#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        if(s.size() == 2) {
            return s[0] == s[1] ? s : string(1, s[0]);
        }

        string longest = "";
        int leftIndex = 0;
        int rightIndex = 0;
        int left = 0;
        int right = s.size()-1;
        bool isPalindrome = false;

        while(left < right) {
            if(s[left] == s[right]) {
                if(!isPalindrome) {
                    leftIndex = left;
                    rightIndex = right;
                    isPalindrome = true;
                }
            } else {
                leftIndex = 0;
                rightIndex = 0;
                isPalindrome = false;
            }

            if(isPalindrome) {
                left++;
                right--;
                continue;
            }
            
            if(s[left+1] == s[right] && s[right-1] != s[left]) {
                left++;
            }
            else if(s[right-1] == s[left] && s[left+1] != s[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }

        for(int i = leftIndex; i <= rightIndex; i++) {
            longest += s[i];
        }

        return longest;
    }
};


// This problem should be solved using dinamic porgramming with tabulation