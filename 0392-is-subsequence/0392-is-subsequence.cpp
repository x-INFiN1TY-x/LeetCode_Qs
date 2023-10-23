class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        int ptr2 = 0;
        int ss = s.size();
        int ts = t.size();
        while (ptr < ss && ptr2 < ts) {
            if (s[ptr] == t[ptr2]) {
                ptr++;
            }
            ptr2++;
        }
        return ptr == ss;
    }
};
