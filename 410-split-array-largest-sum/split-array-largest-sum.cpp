class Solution {
public:
    bool split(vector<int>& nums, int k, int mid, int n) {
        int count = 1;  
        int current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (current_sum + nums[i] > mid) {
                count++;  
                current_sum = nums[i]; 
                if (count > k) return false;  
            } else {
                current_sum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            return -1; 
        }

        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);  
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (split(nums, k, mid, n)) {
                answer = mid;  
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }

        return answer;
    }
};
