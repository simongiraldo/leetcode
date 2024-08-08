#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        int totalProfit = 0;
        int previous = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            // detect a increase point
            if(prices[i] > previous) {
                // calculate rise profit
               totalProfit += (prices[i] - previous); 
            }

            previous = prices[i];
        }

        return totalProfit;
    }
};