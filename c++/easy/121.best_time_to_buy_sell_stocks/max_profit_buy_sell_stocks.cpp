#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        int min = prices[0];
        int max = prices[1];

        int previousBiggestProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < min) {
                if((max - min) > previousBiggestProfit) {
                    previousBiggestProfit = max - min;
                }
                min = prices[i];
                max = 0;
            }

            if(prices[i] > max) {
                max = prices[i];
            }
        }

        int finalProfit = (max - min) > 0 ? (max - min) : 0;
        finalProfit = finalProfit < previousBiggestProfit? previousBiggestProfit : finalProfit;

        return finalProfit;
    }
};