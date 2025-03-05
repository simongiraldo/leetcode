class Solution {
public:
    long long coloredCells(int n) {
        int maxLevel = n + (n-1);
        long long colored = maxLevel;
        int nextLevel = maxLevel - 2;

        while(nextLevel >= 1) {
            colored += nextLevel * 2;
            nextLevel -= 2;
        }

        return colored;
    }
};