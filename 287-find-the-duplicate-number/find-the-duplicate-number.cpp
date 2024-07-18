class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_map<int,int> um;
       for(int num:nums)um[num]++;
       for(auto it:um){
        if(it.second>1)return it.first;
       }
        return 0;
    }
};