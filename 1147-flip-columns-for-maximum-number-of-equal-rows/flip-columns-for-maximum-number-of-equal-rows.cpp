class Solution {
private:
    void convertVectorToString(vector<int>& mat, unordered_map<string, int>& mp,
                               bool flip) {
        string ans = "";
        for (int i = 0; i < mat.size(); i++) {
            int value = flip ? !mat[i] : mat[i];
            ans += to_string(value);
        }
        mp[ans]++;
        return;
    }

public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0)
                convertVectorToString(matrix[i], mp, false);
            else if (matrix[i][0] == 1)
                convertVectorToString(matrix[i], mp, true);
        }
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};