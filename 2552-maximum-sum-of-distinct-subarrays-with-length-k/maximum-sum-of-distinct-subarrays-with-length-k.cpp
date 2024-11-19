class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mp;
        long long maxi=0;
        int i=0,j=0,n=nums.size();
        long long sum=0;
        while(j<n){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1 > k){
                sum-=nums[i];
                if(mp[nums[i]]<=1) mp.erase(nums[i]);
                else mp[nums[i]]--;
                i++;
            }
            if(mp.size() == k){
                maxi = max(maxi, sum);
            }
            j++;
        }
        return maxi;
    }
};