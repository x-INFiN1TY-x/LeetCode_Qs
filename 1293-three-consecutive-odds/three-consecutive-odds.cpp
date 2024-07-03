class Solution {
public:
    bool threeConsecutiveOdds(vector<int> &arr) {
        for (int i = 0; i + 2 < arr.size(); i++) {
            // Check if arr[i], arr[i+1], and arr[i+2] are odd
            if (arr[i] & 1 && arr[i + 1] & 1 && arr[i + 2] & 1)
                return true;
        }
        return false;
    }
};

auto init =[]()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();