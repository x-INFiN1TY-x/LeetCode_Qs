class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        
        int min = 100000;
        int minQuotient= 1;
        int currentValue = n;
        int result = 0;
        
        while (currentValue != 1) {
            for (int j = 1; j <= n; ++j) {
                if (currentValue % j == 0) {
                    auto tmp = currentValue / j;
                    if (tmp != 1) {
                        min = std::min(min, tmp);
                        minQuotient = j;
                    }
                }
            }
            result += min;
            currentValue = minQuotient;
            min = 1000;
        }

        return result;
    }
};