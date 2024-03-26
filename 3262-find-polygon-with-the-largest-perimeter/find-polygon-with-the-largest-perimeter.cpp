class Solution {
public:
    using LL = long long;
    using VI = vector<int>;
    LL largestPerimeter(VI& A) {
        sort(A.rbegin(), A.rend());
        auto t = accumulate(A.begin(), A.end(), 0LL, [](auto t, auto x) { return t + x; });
        for (auto hi: A) {
            t -= hi;
            if (hi < t)
                return hi + t;
        }
        return -1;
    }
};