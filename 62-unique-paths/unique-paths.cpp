class Solution {
public:
    int compute(vector<vector<int>>& grid, vector<vector<int>>& dp, int m,
                int n) {
        if (m == 0 && n == 0)
            return dp[m][n]=1;
        if (m < 0 || n < 0)
            return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int left = compute(grid, dp, m, n - 1);
        int up = compute(grid, dp, m - 1, n);
        return dp[m][n]=left+up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<vector<int>> grid(m,vector<int>(n,0));
        compute(grid,dp,m-1,n-1);
        return dp[m-1][n-1];
    }
};