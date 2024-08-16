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
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = 0;
        ahead[1] = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int j = 0; j < 2; j++) {
                int profit = 0;
                if (j) {
                    profit = max((-prices[index] + ahead[0]),
                                 ahead[1]);
                } else {
                    profit = max((prices[index] + ahead[1]),
                                 ahead[0]);
                }
                curr[j] = profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};