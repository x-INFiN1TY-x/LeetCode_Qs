class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int opened = 0;  // count of opened parentheses

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result += c;  // add '(' only if it's not the outermost '('
                }
                opened++;
            } else if (c == ')') {
                opened--;
                if (opened > 0) {
                    result += c;  // add ')' only if it's not the outermost ')'
                }
            }
        }

        return result;
    }
};
