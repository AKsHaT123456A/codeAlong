class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int k = count(nums.begin(), nums.end(), 1);
        if (k == 0 || k == n) return 0;
        int maxOnes = 0, currentOnes = 0;
        for (int i = 0; i < k; i++) {
            if (nums[i] == 1) currentOnes++;
        }
        maxOnes = currentOnes;
        for (int i = k; i < n + k; i++) {
            if (nums[i % n] == 1) currentOnes++;
            if (nums[(i - k) % n] == 1) currentOnes--;
            maxOnes = std::max(maxOnes, currentOnes);
        }
        int minSwaps = k - maxOnes;
        return minSwaps;
    }
};
