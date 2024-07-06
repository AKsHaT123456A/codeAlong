class Solution {

public:
    void combination(int i, int target, vector<int>& candidates,
                     vector<int>& nums, vector<vector<int>>& ans) {
        if (i==candidates.size()) {
            if(target==0)
            ans.push_back(nums);
            return;
        }
        if (candidates[i] <= target) {
            nums.push_back(candidates[i]);
            combination(i, target - candidates[i], candidates, nums,ans);
            nums.pop_back();
        }
        combination(i + 1, target, candidates, nums,ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        combination(0, target, candidates, nums, ans);
        return ans;
    }
};