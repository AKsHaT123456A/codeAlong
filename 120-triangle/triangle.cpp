class Solution {
public:
    int minimum(vector<vector<int>>& grid, vector<vector<int>>& dp, int i,
                int j,int m) {
        if (i == m-1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int just_up = grid[i][j] +minimum(grid, dp, i+1, j,m);
        int right_up =grid[i][j] + minimum(grid, dp, i + 1, j+ 1,m);
        return dp[i][j] = min(just_up, right_up);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
       return minimum(grid, dp, 0, 0,m);
    }
};