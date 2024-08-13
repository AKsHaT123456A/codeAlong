class Solution {
private:
    void combination(int i, int target, vector<int>& candidates,
                     vector<int>& nums, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                return;
            nums.push_back(candidates[j]);
            combination(j + 1, target - candidates[j], candidates, nums, ans);
            nums.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        combination(0, target, candidates, nums, ans);
        return ans;
    }
};