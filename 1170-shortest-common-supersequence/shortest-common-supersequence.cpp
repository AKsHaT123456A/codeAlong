class Solution {
public:
    string longestCommonSubstr(string s, string t, map<char, int>& mp) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string lcs = "";
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                lcs = s[i - 1] + lcs;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return lcs;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        map<char, int> mp;
        string lcs = longestCommonSubstr(str1, str2, mp);

        int i = 0, j = 0;
        string scs = "";
        for (char c : lcs) {
            while (str1[i] != c) scs += str1[i++];
            while (str2[j] != c) scs += str2[j++];
            scs += c;
            i++;
            j++;
        }

        scs += str1.substr(i) + str2.substr(j);
        return scs;
    }
};
