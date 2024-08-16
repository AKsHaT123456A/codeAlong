class Solution {
public:
    int maxP(vector<int>& prices, int index, int buyStatus, int n, vector<vector<int>> &dp) {
        int profit=0;
        if (index == n)
            return 0;
        if(dp[index][buyStatus]!=-1)return dp[index][buyStatus];
        if (buyStatus) {
             profit =
                max((-prices[index] + maxP(prices, index + 1, 0, n, dp)),
                    maxP(prices, index + 1, 1, n, dp));
        } else
            profit =
                max((prices[index] + maxP(prices, index + 1, 1, n, dp)),
                    maxP(prices, index + 1, 0, n, dp));
        return dp[index][buyStatus]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxP(prices, 0, 1, n, dp);
    }
};