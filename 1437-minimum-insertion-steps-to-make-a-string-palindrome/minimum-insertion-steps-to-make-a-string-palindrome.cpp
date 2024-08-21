class Solution {
public:
    int lcs(string& s, int index1, int index2, vector<vector<int>>& dp) {
        if (index1 < 0 || index2 >= s.size())
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (s[index1] == s[index2])
            return dp[index1][index2] = 1 + lcs(s, index1 - 1, index2 + 1, dp);
        return dp[index1][index2] = max(lcs(s, index1 - 1, index2, dp),
                                        lcs(s, index1, index2 + 1, dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
         int l=lcs(s, n - 1, 0, dp);
        return n -l;
    }
};