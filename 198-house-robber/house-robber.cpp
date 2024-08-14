class Solution {
public:
    int robbing(vector<int> &nums,vector<int> &dp,int index){
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int rob=nums[index]+robbing(nums,dp,index-2);
        int not_rob=robbing(nums,dp,index-1);
        return dp[index]=max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        robbing(nums,dp,n-1);
        return dp[n-1];
    }
};