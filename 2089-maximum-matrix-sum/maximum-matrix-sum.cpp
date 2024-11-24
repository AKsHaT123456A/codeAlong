class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        long long sum = 0;
        int negative = 0;
        int mini = INT_MAX;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int value = matrix[i][j];
                sum += abs(value);           
                if (value < 0) negative++;   
                mini = min(mini, abs(value));
            }
        }
        if (negative % 2 != 0) {
            sum -= 2 * mini;
        }

        return sum;
    }
};
