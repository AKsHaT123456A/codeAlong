class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int l = 0;
        int maxfreq = 0;
        vector<int> um(26, 0);
        
        for (int r = 0; r < s.size(); ++r) {
            um[s[r] - 'A']++;
            maxfreq = max(maxfreq, um[s[r] - 'A']);
            
            while (r - l + 1 - maxfreq > k) {
                um[s[l] - 'A']--;
                l++;
                maxfreq = *max_element(um.begin(), um.end());
            }
            
            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
