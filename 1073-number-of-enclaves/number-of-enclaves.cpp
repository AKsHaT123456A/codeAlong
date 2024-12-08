class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        auto dfs = [&](int row, int col) {
            stack<pair<int, int>> stk;
            stk.push({row, col});
            grid[row][col] = 0;

            while (!stk.empty()) {
                auto [r, c] = stk.top();
                stk.pop();
                for (auto& [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {
                        stk.push({nr, nc});
                        grid[nr][nc] = 0;
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(0, j);
            if (grid[n - 1][j] == 1)
                dfs(n - 1, j);
        }
        int enclaveCount = 0;
        for (const auto& row : grid) {
            enclaveCount += count(row.begin(), row.end(), 1);
        }

        return enclaveCount;
    }
};
