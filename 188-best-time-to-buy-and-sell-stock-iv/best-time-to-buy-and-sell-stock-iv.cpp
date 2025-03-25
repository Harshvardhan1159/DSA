class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int c = 0; c < k; c++) { // Max `k` transactions
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[i] + dp[i + 1][0][c], dp[i + 1][1][c]);  // Buy or skip
                    } else {
                        profit = max(prices[i] + dp[i + 1][1][c + 1], dp[i + 1][0][c]);  // Sell or skip
                    }
                    dp[i][buy][c] = profit;
                }
            }
        }
        return dp[0][1][0]; // Start from day 0, buying allowed, 0 transactions done  
    }
};