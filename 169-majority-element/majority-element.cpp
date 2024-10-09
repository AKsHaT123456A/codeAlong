class Solution {
public:
     static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    int majorityElement(vector<int>& nums) {
       map<int,int>mp;
       for(auto num:nums){
        mp[num]++;
       } 
    vector<pair<int, int>> freq(mp.begin(), mp.end());
    sort(freq.begin(),freq.end(),comp);
       return freq[0].first;
    }
};