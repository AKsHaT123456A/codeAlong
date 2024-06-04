class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> palind;
        int ans = 0;
        int odd = 0;
        if (s.size() == 1) return 1;
        for (auto i : s) {
            palind[i]++;
        }
        for (auto i : palind) {
            ans += (i.second / 2) * 2;
            if (i.second % 2 != 0) {
                odd++;
            }
        }
        return ans + (odd > 0 ? 1 : 0);
    }
};
