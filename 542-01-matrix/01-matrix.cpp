class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> index = q.front();
            q.pop();
            for (auto& x : dir) {
                int dRow = index.first + x[0];
                int dCol = index.second + x[1];
                if (dRow >= 0 && dRow < n && dCol >= 0 && dCol < m &&
                    dis[dRow][dCol] == -1) {
                    q.push({dRow, dCol});
                    dis[dRow][dCol] = dis[index.first][index.second] + 1;
                }
            }
        }
        return dis;
    }
};