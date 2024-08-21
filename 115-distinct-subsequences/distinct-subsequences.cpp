class Solution {
public:
    int prime = 1e9 + 7;
    vector<vector<int>> dp; 
    int distinct(string &s, string &t, int i1, int i2){
        if(i2 < 0) return 1;
        if(i1 < 0) return 0; 
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s[i1] == t[i2])
            dp[i1][i2] = (distinct(s, t, i1 - 1, i2 - 1) + distinct(s, t, i1 - 1, i2)) % prime;
        else
            dp[i1][i2] = distinct(s, t, i1 - 1, i2) % prime;

        return dp[i1][i2];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n, vector<int>(m, -1)); 
        return distinct(s, t, n - 1, m - 1);
    }
};
