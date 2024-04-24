class Solution {
private:
    int rob(vector<int>& nums,int start,int end,int n) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i=start;i<end;i++) {
            int tmp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = tmp;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 0)
            return 0;
        if(n==1)return nums[0];
        return max(rob(nums,0,n-1,n),rob(nums,1,n,n));
    }
};
