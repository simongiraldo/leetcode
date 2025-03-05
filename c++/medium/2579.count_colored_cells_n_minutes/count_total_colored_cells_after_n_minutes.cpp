#include <iostream>

using namspace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long centerSquare = 1LL * n * n;
        long long edges = 1LL * (n-1) * (n-1);
        return centerSquare + edges;
    }
};