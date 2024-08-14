class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp = matrix;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int leftDiagonal = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rightDiagonal = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] += min({up, leftDiagonal, rightDiagonal});
            }
        }

        int result = INT_MAX;
        for (int j = 0; j < m; j++) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};
