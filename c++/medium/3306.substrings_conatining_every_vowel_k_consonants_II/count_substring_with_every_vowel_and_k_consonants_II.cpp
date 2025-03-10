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
        unordered_map<char, int> vowelCount;
        
        if (this->isVowel(word[left])) 
            vowelCount[word[left]] = 1;
            
        while(left < word.size()+1 - (k+5)) {
            char letter = word[right];
            if(right > word.size()-1) {
                letter = word[left];
                right = word.size()-1;
            } else {
                if (this->isVowel(letter)) {
                vowels++;
                vowelCount[letter]++;
            }
            }
            
            int consonants = right + 1 - left - vowels;
            /*
            for(int i = left; i <= right; i++) {
                cout<<word[i];
            }
            cout<<endl;
            
            cout << "Left: " << left << " , right: " << right << endl;
            cout << "Vowels: " << vowels << " , consonants: " << consonants<<endl;
            cout<<"substrings: "<<substrings<<endl;
            cout<<"vowelCount: "<<vowelCount.size()<<endl<<endl;
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
                if(right == word.size()-1) {
                    if(vowelCount[word[left]] > 1) {
                        vowelCount[word[left]]--;
                    } else {
                        vowelCount.erase(word[left]);
                    }
                    vowels -= this->isVowel(word[left]);
                    //cout<<"New vowels mov Left: "<<vowels<<endl<<endl;
                    left++;
                }
                right++;
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
    /*
    string case3 = "ieaouqqieaouqq"; // k=1, result = 3
    long long result3 = sn->countOfSubstrings(case3, 1);
    cout<<"Result for "<<case3<<": "<<result3<<endl;
    */
    string case0 = "iqeaouqi"; // k=2, result = 3
    long long test0 = sn->countOfSubstrings(case0, 2);
    string result0 = test0 == 3 ? "PASS" : "FAIL";
    cout<<"Result for "<<case0<<": "<<test0<<"  "<<result0<<endl;
    
    string case1 = "aoaiuefi";
    long long test1 = sn->countOfSubstrings(case1, 1);
    string result1 = test1 == 4 ? "PASS" : "FAIL";
    cout<<"Result for "<<case1<<": "<<test1<<"  "<<result1<<endl;
    
    string case2 = "aeioqq";
    long long test2 = sn->countOfSubstrings(case2, 1);
    string result2 = test2 == 0 ? "PASS" : "FAIL";
    cout<<"Result for "<<case2<<": "<<test2<<"  "<<result2<<endl;
    
    string case3 = "aeiou";
    long long test3 = sn->countOfSubstrings(case3, 0);
    string result3 = test3 == 1 ? "PASS" : "FAIL";
    cout<<"Result for "<<case3<<": "<<test3<<"  "<<result3<<endl;
    
    string case4 = "ieaouqqieaouqq";
    long long test4 = sn->countOfSubstrings(case4, 1);
    string result4 = test4 == 3 ? "PASS" : "FAIL";
    cout<<"Result for "<<case4<<": "<<test4<<"  "<<result4<<endl;


    return 0;
}