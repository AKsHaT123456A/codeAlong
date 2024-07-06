class Solution {
    vector<vector<int>> ans;

public:
    void combination(int i, int target, vector<int>& candidates,vector<int>& nums) {
         if (target == 0) {
            ans.push_back(nums);
            return;
        }
        if (i == candidates.size() || target < 0) {
            return;
        }
        if (candidates[i] <= target) {
            nums.push_back(candidates[i]);
            combination(i, target - candidates[i], candidates, nums);
            nums.pop_back();
        }
        combination(i + 1, target, candidates, nums);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        combination(0, target, candidates, nums);
        return ans;
    }
};