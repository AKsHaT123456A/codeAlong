class Solution {
public:
   vector<int> resultsArray(vector<int>& nums, int k) {
        int left=0, right=0;
        int n = nums.size();
        if(k==1) return nums;
        bool flag = true;
        vector<int> ans;
        while(right<n){
            if(right-left+1==k){
                flag = true;
                int maxEle=-1;
                for(int i=left;i<right;i++){
                    if((nums[i+1]-nums[i])==1)maxEle=max(maxEle,nums[i+1]);
                    else flag = false;
                }
                if(!flag) maxEle = -1;
                ans.push_back(maxEle);
                left++;
            }
            right++;
        }
        return ans;
    }
};