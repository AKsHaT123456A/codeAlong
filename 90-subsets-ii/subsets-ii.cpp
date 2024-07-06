
class Solution {
public:
    void subset(vector<int>& arr, int i, vector<int>& s, vector<vector<int>>& ans) {
        ans.push_back(s);
        for (int j = i; j < arr.size(); ++j) {
            if (j > i && arr[j] == arr[j - 1]) continue; // Skip duplicates
            s.push_back(arr[j]);
            subset(arr, j + 1, s, ans);
            s.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> s;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        subset(nums, 0, s, ans);
        return ans;
    }
};