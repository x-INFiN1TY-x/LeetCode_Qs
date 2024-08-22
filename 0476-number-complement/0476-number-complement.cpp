// OJ: https://leetcode.com/problems/number-complement/
// Author: github.com/lzl124631x
// Time: O(1) as there are at most 32 bits to move
// Space: O(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};