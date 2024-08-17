class Solution {
public:
    int coin(int amount, vector<int>& coins, vector<vector<int>>& dp,
             int index) {
        if (index == 0) {
            return dp[0][amount]=(amount % coins[0] == 0);
        }
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int not_take = coin(amount, coins, dp, index - 1);
        int take = 0;
        if (coins[index] <= amount) {
            take = coin(amount - coins[index], coins, dp, index);
        }
        return dp[index][amount] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        coin(amount, coins, dp, n - 1);
        return dp[n - 1][amount];
    }
};