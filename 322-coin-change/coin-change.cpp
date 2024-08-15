class Solution {
public:
    
int coin(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
    if (amount == 0) return 0; 
    if (index == 0) {
        if (amount % coins[0] == 0) return amount / coins[0];
        else return INT_MAX - 1;
    }

    if (dp[index][amount] != -1) return dp[index][amount];

    int not_take = coin(coins, amount, index - 1, dp);
    int take = INT_MAX - 1; 

    if (coins[index] <= amount) {
        take = 1 + coin(coins, amount - coins[index], index, dp);
    }

    dp[index][amount] = min(take, not_take);
    return dp[index][amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int result = coin(coins, amount, n - 1, dp);
    return (result == INT_MAX - 1) ? -1 : result; 
}
};