#include <string>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0;
        
        std::bitset<256> a;  // Change bitset size to 256 to handle all ASCII characters
        int left = 0, right = 0, maxLength = 0;
        
        while (right < s.size()) {
            if (a[s[right]]) {
                a[s[left]] = 0;
                left++;
            } else {
                a[s[right]] = 1;
                right++;
                maxLength = std::max(maxLength, right - left);
            }
        }
        
        return maxLength;
    }
};
