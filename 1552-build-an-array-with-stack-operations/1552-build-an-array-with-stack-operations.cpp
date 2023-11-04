class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        int last = target[target.size() - 1];
        if (last > n) return res;

        int x = 1, i, tpush, tpop;
        tpop = tpush = i = 0;

        while (last != tpush) {
            if (target[i] == x) {
                res.push_back("Push");
                tpush++;
                i++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
                tpush++;
                tpop++;
            }
            x++;

        }

        return res;
    }
};
