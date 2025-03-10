/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        if (word.size() < k + 5)
            return 0;
        int left = 0;
        int right = 1;
        int vowels = this->isVowel(word[left]);
        long long substrings = 0;
        unordered_map<int, int> vowelCount;
        if (this->isVowel(word[left])) 
            vowelCount[word[left]] = 1;
            
        while(left < word.size()+1 - (k+5)) {
            char letter = word[right];
            if(right+1 == word.size()) {
                letter = word[left];
            }
            
            if (this->isVowel(letter)) {
                vowels++;
                vowelCount[letter]++;
            }
            
            int consonants = right + 1 - left - vowels;
            
            for(int i = left; i <= right; i++) {
                cout<<word[i];
            }
            cout<<endl;
            /*
            cout << "Left: " << left << " , right: " << right << endl;
            cout << "Vowels: " << vowels << " , consonants: " << consonants<<endl;
            cout<<"substrings: "<<substrings<<endl<< endl;
            */
                 
            if (vowelCount.size() < 5 || consonants < k) {
                if(right+1 == word.size()) {
                    if(vowelCount[word[left]] > 1) {
                        vowelCount[word[left]]--;
                    } else {
                        vowelCount.erase(word[left]);
                    }
                    vowels -= this->isVowel(word[left]);
                    left++;
                } else {
                    right++;
                }
                continue;
            }
            
            if (consonants == k) {
                substrings++;
                if(right+1 == word.size()) {
                    if(vowelCount[word[left]] > 1) {
                        vowelCount[word[left]]--;
                    } else {
                        vowelCount.erase(word[left]);
                    }
                    vowels -= this->isVowel(word[left]);
                    left++;
                } else {
                    right++;
                }
                continue;
            }
            
            if (consonants > k) {
                if((!this->isVowel(word[right]) && this->isVowel(word[left]))) {
                    right--;
                } else if(this->isVowel(word[right])){
                    vowels--;
                    if(vowelCount[word[right]] > 1) {
                        vowelCount[word[right]]--;
                    } else {
                        vowelCount.erase(word[right]);
                    }
                }
                
                if(vowelCount[word[left]] > 1) {
                    vowelCount[word[left]]--;
                } else {
                    vowelCount.erase(word[left]);
                }
                vowels -= this->isVowel(word[left]);
                left++;
            }
        }
       
        return substrings;
    }
};

int main()
{   
    Solution* sn = new Solution();
    
    string case3 = "iqeaouqi"; // k=2, result = 3
    long long result3 = sn->countOfSubstrings(case3, 2);
    cout<<"Result for "<<case3<<": "<<result3<<endl;

    return 0;
}