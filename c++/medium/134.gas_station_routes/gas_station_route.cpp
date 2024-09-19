#include <vector>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 1) return gas[0] >= cost[0] ? 0 : -1;

        int nextStation = 0;
        int currentStation = 0;
        int start = 0;
        int startsCheked = 0;
        while(startsCheked < gas.size()) {
            currentStation = start;
            nextStation = start;
            int currentGas = 0;
            int count = 0;
            for(int i = 0; i < gas.size(); i++) {
                count++;
                nextStation = nextStation < gas.size()-1 ? nextStation+1 : 0;

                currentGas += gas[currentStation];

                if(currentGas - cost[currentStation] >= 0) {
                    currentGas -= cost[currentStation];
                } else break;

                if(nextStation == start) {
                    return start;
                }

                currentStation = nextStation;
            }

            startsCheked += count;
            start = currentStation+1;
        }

        return -1;
    }
};