class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;

    vector<int> firstProfit(n, 0);
    vector<int> secondProfit(n, 0);
    
    // First transaction
    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        firstProfit[i] = max(firstProfit[i - 1], prices[i] - minPrice);
    }

    // Second transaction
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxPrice = max(maxPrice, prices[i]);
        secondProfit[i] = max(secondProfit[i + 1], maxPrice - prices[i]);
    }

    // Combine both profits
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, firstProfit[i] + secondProfit[i]);
    }
    return maxProfit;
}
};