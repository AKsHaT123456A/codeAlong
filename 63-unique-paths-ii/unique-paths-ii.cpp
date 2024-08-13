class Solution {
public:
    int compute(vector<vector<int>>& grid, vector<vector<int>>& dp, int m,
                int n) {
        if (m == 0 && n == 0)
           return dp[m][n]= 1;
        if (m < 0 || n < 0 || grid[m][n] == 1)return 0;  
        if (dp[m][n] != -1)
            return dp[m][n];
        int left = compute(grid, dp, m, n - 1);
        int up = compute(grid, dp, m - 1, n);
        return dp[m][n] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        compute(obstacleGrid, dp, m - 1, n - 1);
        return dp[m - 1][n - 1];
    }
};