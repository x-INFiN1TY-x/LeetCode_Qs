static int _ = [](){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        for (auto i : arr) {
            q.push(i);
        }
        int one = q.front();
        q.pop();
        int x = k;
        int maxi = *max_element(arr.begin(), arr.end());
        if (k >= arr.size()) {
            return maxi;
        }
        while (k) {
            int two = q.front();
            q.pop();
            if (one > two) {
                k--;
                q.push(two);
            } else {
                k = x;
                k--;
                q.push(one);
                one = two;
            }
        }
        return one;
    }
};