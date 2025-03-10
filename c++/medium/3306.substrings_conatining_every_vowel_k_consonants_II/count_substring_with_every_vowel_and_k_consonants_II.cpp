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

        while (right < word.size()) {
            if (this->isVowel(word[right])) {
                vowels++;
                vowelCount[word[right]]++;
            }

            int consonants = right + 1 - left - vowels;
            cout << "Left: " << left << " , right: " << right << endl;
            cout << "Vowels: " << vowels << " , consonants: " << consonants
                 << endl
                 << endl;

            if (vowelCount.size() < 5 || consonants < k) {
                right++;
                continue;
            }

            if (consonants == k) {
                substrings++;
            }

            if (consonants > k) {
                int consonantsTaken = 0;
                while (consonantsTaken < consonants - k && left < right) {
                    if (this->isVowel(word[left])) {
                        if(vowelCount[word[left]] > 1) {
                            vowelCount[word[left]]--;
                        } else {
                           vowelCount.erase(word[left]);
                        }
                        vowels--;
                    } else {
                        consonantsTaken++;
                    }
                    left++;
                }
                if (left == right) {
                    if (this->isVowel(word[left])) {
                        vowelCount[word[left]] = 1;
                        vowels = 1;
                    }
                }

                consonants = right + 1 - left - vowels;
                if (vowelCount.size() == 5 && consonants == k) {
                    substrings++;
                }
            }

            right++;
        }

        right = word.size() - 1;
        vowels -= this->isVowel(word[left]);
        if(vowelCount[word[left]] > 1) {
            vowelCount[word[left]]--;
        } else {
            vowelCount.erase(word[left]);
        }
        left++;
        while(word.size() - left >= k + 5) {
            int consonants = right + 1 - left - vowels;
            if (vowelCount.size() == 5 && consonants == k) {
                substrings++;
            }

            if (this->isVowel(word[left])) {
                vowels--;
                vowelCount.erase(word[left]);
            }
            left++;
        }

        return substrings;
    }
};