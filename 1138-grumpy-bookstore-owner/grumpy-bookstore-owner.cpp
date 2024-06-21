class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currentSum = 0;
        
        // Initial sum calculation for the first window
        for (int i = 0; i < minutes; ++i) {
            currentSum += customers[i] * grumpy[i];
        }
        
        int maxWindowSum = currentSum;
        int bestStartIndex = 0;
        
        // Sliding window to find the maximum sum of customers that can be satisfied within `minutes`
        for (int i = minutes; i < n; ++i) {
            currentSum += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
            if (currentSum > maxWindowSum) {
                maxWindowSum = currentSum;
                bestStartIndex = i - minutes + 1;
            }
        }

        int totalSatisfaction = 0;

        // Calculate the total satisfaction including the best "non-grumpy" period
        for (int i = 0; i < n; ++i) {
            if (i >= bestStartIndex && i < bestStartIndex + minutes) {
                totalSatisfaction += customers[i];
            } else if (grumpy[i] == 0) {
                totalSatisfaction += customers[i];
            }
        }

        return totalSatisfaction;
    }
};