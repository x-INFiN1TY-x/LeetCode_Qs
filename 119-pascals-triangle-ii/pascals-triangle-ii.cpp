#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long nCr(int n, int r) {
        if (r == 0 || r == n)
            return 1;
        if (r == 1)
            return n;
        if (r > n - r)
            r = n - r;

        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= n - i + 1;
            result /= i;
        }
        return result;
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr(rowIndex + 1, 1);
        if (rowIndex <= 1)
            return arr;
        for (int i = 1; i < rowIndex; ++i) {
            arr[i] = static_cast<int>(nCr(rowIndex, i));
        }
        return arr;
    }
};
