class Solution {
public:
    string removeOuterParentheses(string s) {
        int c = 0;
        string r = "";
        for (auto a : s) {
            if (!c && a == '(') {
                c++;
                continue;
            }
            if (a == ')' && c == 1) {
                c--;
                continue;
            }
            if (a == '(' && c) {
                r += a;
                c++;
            }
            if (a == ')' && c) {
                r += a;
                c--;
            }
        }
        return r;
    }
};