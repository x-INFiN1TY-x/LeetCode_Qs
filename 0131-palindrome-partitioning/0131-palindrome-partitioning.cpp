static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    static vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(0, tmp, s, res);
        return res;
    }

    static constexpr bool isPalindrome(const string& str) {
        for (int l = 0, r = str.size() - 1; l < r; ++l, --r)
            if (str[l] != str[r]) return false;
        return true;
    }

    static void dfs(int i, vector<string>& cur, const string& s, vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int start = i; i < s.size(); ++i) {
            cur.push_back(s.substr(start, i - start + 1));
            if (isPalindrome(cur.back()))
                dfs(i + 1, cur, s, res);
            cur.pop_back();
        }
    }
};

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        vector<vector<string>> res = Solution::partition(str.substr(1, str.size() - 2));
        cout << '[';
        bool a = true;
        for (const auto& v : res) {
            if (a) a = false;
            else cout << ',';
            cout << '[';
            bool b = true;
            for (const auto& s : v) {
                if (b) b = false;
                else cout << ',';
                cout << '\"' << s << '\"';

            }
            cout << ']';

        }
        cout << ']';
    }
    exit(0);
    return 0;
}();