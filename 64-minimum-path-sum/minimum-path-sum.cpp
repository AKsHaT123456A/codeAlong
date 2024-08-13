class Solution {
public:
    int compute(vector<vector<int>>& grid, vector<vector<int>>& dp, int m,
                int n) {
        if (m == 0 && n == 0)
            return dp[m][n] = grid[m][n];
        if (dp[m][n] != -1)
            return dp[m][n];
        long long left = (n>0)?compute(grid, dp, m, n - 1):INT_MAX;
        long long up = (m>0)?compute(grid, dp, m - 1, n):INT_MAX;
        return dp[m][n] = grid[m][n]+min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        compute(grid,dp,m-1,n-1);
        return dp[m-1][n-1];
    }
};