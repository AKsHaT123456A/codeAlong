class Solution {
public:
    bool Partition(vector<int>& arr, int index, int sum,
                   vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (index == 0)
            return (arr[0] == sum);
        if (dp[index][sum] != -1)
            return dp[index][sum];
        bool not_take = Partition(arr, index - 1, sum, dp);
        bool take = false;
        if (arr[index] <= sum) {
            take = Partition(arr, index - 1, sum - arr[index], dp);
        }
        return dp[index][sum] = (not_take || take);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return Partition(nums, nums.size() - 1, sum,dp);
    }
};