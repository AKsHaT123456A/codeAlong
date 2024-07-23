class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> sortFreq;
        vector<pair<int, int>> sortedFreqs;
        for (int num : nums) {
            sortFreq[num]++;
        }
        for (auto it : sortFreq) {
            sortedFreqs.push_back({it.first, it.second});
        }
        sort(sortedFreqs.begin(), sortedFreqs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;  
            }
            return a.second < b.second; 
        });
        vector<int> result;
        for (auto& p : sortedFreqs) {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};