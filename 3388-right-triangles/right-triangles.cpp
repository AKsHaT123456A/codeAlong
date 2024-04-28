#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();  

        vector<int> rowSum(m, 0);
        vector<int> columnSum(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                columnSum[j] += grid[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += (grid[i][j]) * (rowSum[i] - 1) * (columnSum[j] - 1);
            }
        }
        return ans;
    }
};
