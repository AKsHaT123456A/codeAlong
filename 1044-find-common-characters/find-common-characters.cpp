class Solution {
public:
    void filler(string w, vector<int> &count) {
        for (auto ch : w) {
            count[ch - 'a']++;
        }
    }

public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, 0);
        vector<string> ans;
        filler(words[0], count);
        for (int i = 1; i < words.size(); i++) {
            vector<int> temp(26, 0);
            filler(words[i], temp);
            for (int j = 0; j < 26; j++) {
                count[j] = min(count[j], temp[j]);
            }
        }
        for(int i=0;i<26;i++){
            int c=count[i];
            char s=char(i+97);
            string an="";
            an+=s;
            while(c--)
            ans.push_back(an);
        }
        return ans;

    }
};