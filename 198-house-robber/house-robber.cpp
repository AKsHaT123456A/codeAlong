class Solution {
private:
    int AkshatTheRobber(vector<int>& nums, int i,vector<int> &dp) {
        if (i < 0)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int robCurrent = nums[i] + AkshatTheRobber(nums, i - 2,dp);
        int skipCurrent = AkshatTheRobber(nums, i - 1,dp);
        return dp[i]=max(robCurrent, skipCurrent);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return AkshatTheRobber(nums, n - 1,dp);
    }
};
