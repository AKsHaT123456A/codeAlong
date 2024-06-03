class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        int i = 0; 
        int j = 0; 
        while (i < s_size && j < t_size) {
            if (s[i] == t[j]) {
                j++; 
            }
            i++; 
        }
        return t_size - j;
    }
};
