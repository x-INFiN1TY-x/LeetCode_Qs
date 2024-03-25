class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m = 0; // Initialize m to 0
        for (int i = 0; i < gain.size(); i++) {
            gain[i] = (i == 0) ? gain[i] : gain[i] + gain[i - 1];
            m = max(m, gain[i]);
        }
        return m;
    }
};
