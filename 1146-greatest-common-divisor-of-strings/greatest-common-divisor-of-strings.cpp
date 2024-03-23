#include <string>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if (!(str1.length() && str2.length()))
            return "";
        int gc = gcd(str1.length(), str2.length());
        if (gc) {
            std::string t1(str1.begin(), str1.begin() + gc);
            std::string t2(str2.begin(), str2.begin() + gc);
            if (str2.substr(0, gc) == str1.substr(0, gc)) {
                for (int i = 1; i < str1.length() / gc; ++i)
                    t1 += str1.substr(0, gc);
                for (int i = 1; i < str2.length() / gc; ++i)
                    t2 += str2.substr(0, gc);
                if (t1 == str1 && t2 == str2)
                    return str2.substr(0, gc);
                else
                    return "";
            } else
                return "";
        } else
            return "";
    }
};
