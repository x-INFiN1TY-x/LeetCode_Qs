#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& flowerbed, int i) {
        if (i < 0 || i >= flowerbed.size()) // Added boundary check
            return false;
        if ((i == 0 || flowerbed[i - 1] == 0) &&  // Fixed the condition
            flowerbed[i] == 0 && 
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.front() == 0) {
        if (check(flowerbed, 0)) { // Fixed the function call
                n--;
                flowerbed.front() = 1;
            }
        }
        if (flowerbed.back() == 0) {
            if (check(flowerbed, flowerbed.size()- 1)) { // Fixed the function call
                n--;
                flowerbed.back() = 1;
            }
            }
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (check(flowerbed, i)) { // Fixed the function call
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
