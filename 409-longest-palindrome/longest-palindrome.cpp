class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> palind;
        int ans = 0;
        int odd = 0;
        for (auto i : s) {
            palind[i]++;
            ans += (palind[i] % 2 == 0) ? 2 : 0; 
            if (palind[i] % 2 != 0) odd++; 
            else odd--; 
        }
        return ans + (odd > 0 ? 1 : 0); 
    }
};
