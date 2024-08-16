class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x >= 0 && x <= 9) return true;
        
        long long max = 1;
        while(max*10 < x) {
            max *= 10;
        }

        int divider = (int)max;
        while(x > 0) {
            int num1 = (x/divider);
            int num2 = x % 10;

            if(num1 != num2) return false;

            x -= num2;
            x -= num1 * divider;
            
            divider /= 100;
            x /= 10;
        }

        return true;
    }
};