class Solution {
public:
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken);
        }
    }
    return dp[n-1][tar];
}
int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);
}
    int ways(vector<int>& nums, int target,int index,vector<vector<int>>&dp){
         if (index < 0) return target == 0 ? 1 : 0;
        if(dp[index][target+1000]!=-1)return dp[index][target+1000];
        int minus_take=ways(nums,target+nums[index],index-1,dp);
        int plus_take=ways(nums,target-nums[index],index-1,dp);
        return dp[index][target+1000]=minus_take+plus_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
       return countPartitions(n,target,nums);
    }
};