class Solution {
public:
    static bool isOne(char bit) {
        return bit == '1';
    }

    string maximumOddBinaryNumber(string s) {
        if (count(s.begin(), s.end(), '1') == 1) {
            s = string(s.size(), '0');
            s.back()++;
            return s;
        }
        if (s.back() == '1') {
            s.back()--; // Decrement the last '1' to make the number even
            vector<char> binaryVec(s.begin(), s.end()); // Convert string to vector
            stable_partition(binaryVec.begin(), binaryVec.end(), isOne);
            s = string(binaryVec.begin(), binaryVec.end());
            s.back()++; // Revert the last decremented digit back to '1'
        } else {
            vector<char> binaryVec(s.begin(), s.end()); // Convert string to vector
            auto i = stable_partition(binaryVec.begin(), binaryVec.end(), isOne);
            --(*(i-1)); // Decrement the first '0' to make it '1'
            s = string(binaryVec.begin(), binaryVec.end());
            s.back()++; // Increment the last digit back to '1'
        }
        return s;
    }
};
