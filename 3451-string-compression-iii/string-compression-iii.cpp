#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string res;
        for(int i = 0; i < word.size();) {
            int ct = 1, j = i;
            while(j + 1 < word.size() && word[j + 1] == word[j] && ct < 9) {
                ct++;
                j++;
            }
            res += ('0' + ct); // Append the count as a character
            res += word[i];    // Append the character itself
            i = j + 1;         // Move to the next character after the repeated ones
        }
        return res;
    }
};
