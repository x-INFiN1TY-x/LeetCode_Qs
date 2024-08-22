class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {

            while (i < n && s[i] ==' ') {
                i++;
            }

            if (i == n)
                break;

            while (i < n && s[i] !=' ') {
                s[right++] = s[i];
                i++;
            }

            reverse(s.begin() + left, s.begin() + right);

            s[right++] = ' ';

            left = right;
        }

        s.resize(--right);

        return s;
    }
};