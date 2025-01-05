class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> dna;
        char same;
        int size_same=0;
        if(s.size()<10)return {};
        for (int i = 0; i <= s.size() - 10; i++) {
            string ss = s.substr(i, 10);
            dna[ss]++;
        }
        for(auto it:dna){
            
        }
        vector<string>ans;
        for(auto it:dna){
            if(it.second>1){
                ans.push_back(it.first);
            }

        }
        return ans;
    }
};