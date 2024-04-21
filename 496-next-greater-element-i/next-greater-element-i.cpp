class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        vector<int> v;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>=s.top()){
                s.pop();
            }
            if(s.empty())mp[nums[i]]=-1;
            else mp[nums[i]]=s.top();
            s.push(nums[i]);
        }
        for(int i:findNums){
           v.push_back(mp[i]);
        }
        return v;
    }
};