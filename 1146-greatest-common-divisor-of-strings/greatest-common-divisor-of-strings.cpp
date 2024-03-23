#include <string>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        
        int len1 = str1.length();
        int len2 = str2.length();
        int gcd = 1;
        
        // Calculating gcd
        while (len2 != 0) {
            int temp = len2;
            len2 = len1 % len2;
            len1 = temp;
        }
        gcd = len1;
        
        return str1.substr(0, gcd);
    }
};
