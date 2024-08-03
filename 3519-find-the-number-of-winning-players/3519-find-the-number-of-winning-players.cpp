#include <vector>
#include <unordered_map>

class Solution {
public:
    int winningPlayerCount(int n, std::vector<std::vector<int>>& pick) {
        auto player_color_count = countColorPicks(n, pick);
        return countWinners(n, player_color_count);
    }

private:
    std::vector<std::unordered_map<int, int>> countColorPicks(int n, const std::vector<std::vector<int>>& pick) {
        std::vector<std::unordered_map<int, int>> player_color_count(n);
        
        for (const auto& p : pick) {
            int player = p[0];
            int color = p[1];
            player_color_count[player][color]++;
        }

        return player_color_count;
    }

    int countWinners(int n, const std::vector<std::unordered_map<int, int>>& player_color_count) {
        int winners = 0;

        for (int i = 0; i < n; ++i) {
            for (const auto& entry : player_color_count[i]) {
                if (entry.second > i) {
                    winners++;
                    break;
                }
            }
        }

        return winners;
    }
};
