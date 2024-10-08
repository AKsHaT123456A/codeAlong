class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1,0),curr(n+1,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int not_take = p[prev + 1];
                int take = 0;

                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + p[i + 1];
                }

                curr[prev + 1] = max(take, not_take);
            }
            p=curr;
        }

        return p[0];
    }
};
