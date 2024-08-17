class Solution {
public:
    int lcs(string& s1, string& s2, int ind1, int ind2,
            vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s1[ind1 - 1] == s2[ind2 - 1])
            return dp[ind1][ind2] = 1 + lcs(s1, s2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = 0 + max(lcs(s1, s2, ind1 - 1, ind2, dp),
                                        lcs(s1, s2, ind1, ind2 - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
        }
};