class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorResult=0;
        int cnt=0;
        for(int num:nums)xorResult^=num;
         int result = xorResult ^ k;
         for (int i = 31; i >= 0; i--) {
            if (result & (1 << i)) {
                cnt++;
                }
        }
        return cnt;
    }
};