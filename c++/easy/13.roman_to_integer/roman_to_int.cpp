class Solution {
private:
    unordered_map<char, int> symbols = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int total = 0;
        int num = 0;

        for(int i = 0; i < s.size(); i++) {
            num = symbols[s[i]];

            if(i+1 < s.size() && symbols[s[i+1]] > num) {
                total += symbols[s[++i]] - num;
            } else {
                total += num;
            }
        }

        return total;
        
    }
};