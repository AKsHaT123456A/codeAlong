class Solution {
public:
    int maxP(vector<int>& prices, int index, int buyStatus, int n,
             vector<vector<int>>& dp) {
        int profit = 0;
        if (index == n)
            return 0;
        if (dp[index][buyStatus] != -1)
            return dp[index][buyStatus];
        if (buyStatus) {
            profit = max((-prices[index] + maxP(prices, index + 1, 0, n, dp)),
                         maxP(prices, index + 1, 1, n, dp));
        } else
            profit = max((prices[index] + maxP(prices, index + 1, 1, n, dp)),
                         maxP(prices, index + 1, 0, n, dp));
        return dp[index][buyStatus] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int j = 0; j < 2; j++) {
                int profit = 0;
                if (j) {
                    profit = max((-prices[index] + dp[index + 1][0]),
                                 dp[index + 1][1]);
                } else {
                    profit = max((prices[index] + dp[index + 1][1]),
                                 dp[index + 1][0]);
                }
                 dp[index][j] = profit;
            }
        }
        return dp[0][1];
    }
};