class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int b = nums[i], a = target - b;
            if (mp.count(a))
                return {mp[a], i};
            mp[b] = i;
        }
        return {};
    }
};