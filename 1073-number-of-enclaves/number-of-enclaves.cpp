class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        auto seeOne = [&](int row, int col) {
            queue<pair<int, int>> q;
            q.push({row, col});
            grid[row][col] = 0;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 0;
                    }
                }
            }
        };
         for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                seeOne(i, 0);
            if (grid[i][m - 1] == 1)
                seeOne(i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                seeOne(0, j);
            if (grid[n - 1][j] == 1)
                seeOne(n - 1, j);
        }
        int countOnes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    countOnes++;
                }
            }
        }
        return countOnes;
    }
};