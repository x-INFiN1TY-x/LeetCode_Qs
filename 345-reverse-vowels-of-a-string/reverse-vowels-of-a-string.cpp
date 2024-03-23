#include <string>
#include <unordered_set>

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (start < end && vowels.find(s[start]) == vowels.end()) {
                start++;
            }
            
            while (start < end && vowels.find(s[end]) == vowels.end()) {
                end--;
            }
            
            if (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        
        return s;
    }
};
