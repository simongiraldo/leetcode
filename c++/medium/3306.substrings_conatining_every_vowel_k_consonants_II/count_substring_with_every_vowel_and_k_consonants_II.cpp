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
            
        while(right < word.size()) {
            if (this->isVowel(word[right])) {
                vowels++;
                vowelCount[word[right]]++;
            }
            int consonants = right + 1 - left - vowels;
            
            for(int i = left; i <= right; i++) {
                cout<<word[i];
            }
            cout<<endl;
            /*
            cout<<endl;
            cout << "Left: " << left << " , right: " << right << endl;
            cout << "Vowels: " << vowels << " , consonants: " << consonants<<endl;
            cout<<"substrings: "<<substrings<<endl<< endl;
            */
                 
            if (vowelCount.size() < 5 || consonants < k) {
                right++;
                continue;
            }
            
            if (consonants == k) {
                substrings++;
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