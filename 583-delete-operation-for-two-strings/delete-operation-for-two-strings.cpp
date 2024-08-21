class Solution {
public:
    int lcs(string& s,string&t, int index1, int index2, vector<vector<int>>& dp) {
        if (index1 == 0 || index2==0)
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (s[index1-1] == t[index2-1])
            return dp[index1][index2] = 1 + lcs(s,t, index1 - 1, index2 -1, dp);
        return dp[index1][index2] = max(lcs(s, t,index1 - 1, index2, dp),
                                        lcs(s,t, index1, index2 -1, dp));
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int l= lcs(s,t, n, m, dp);
        return (m-l)+(n-l);
    }
};