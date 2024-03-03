#include <unordered_map>
#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        if(n==1) return 1;
        std::unordered_map<int, int> trustCounts;
        std::unordered_map<int, bool> isTrusted;

        for (const auto& pair : trust) {
            int a = pair[0];
            int b = pair[1];
            trustCounts[b]++;
            isTrusted[a] = true;
        }

        for (const auto& pair : trustCounts) {
            if (pair.second == n - 1 && !isTrusted[pair.first]) {
                return pair.first;
            }
        }

        return -1;
    }
};
