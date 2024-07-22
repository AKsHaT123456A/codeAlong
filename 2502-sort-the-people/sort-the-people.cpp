class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> sortedPair;
        for(int i=0;i<heights.size();i++){
            sortedPair.push_back({heights[i],names[i]});
        }
        sort(sortedPair.rbegin(),sortedPair.rend());
        for(int i=0;i<names.size();i++){
            names[i]=sortedPair[i].second;
        }
        return names;
    }
};