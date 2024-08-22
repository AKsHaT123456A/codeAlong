class Solution {
public:
    int bs(vector<int>& bloomDay, int m, int k, int low, int high, int n) {
        if ((long long)m * k > n) 
            return -1;

        int ans = high;  

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k, n)) {
                ans = mid;  
                high = mid - 1;  
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }

    bool possible(vector<int>& bloomDay, int day, int m, int k, int n) {
        int cnt = 0;  
        int noOf = 0; 
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {  
                    noOf++;
                    cnt = 0;  
                    if (noOf >= m)  
                        return true;
                }
            } else {
                cnt = 0;  
            }
        }
        return noOf >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int high = INT_MIN;
        int low = INT_MAX;

        // Find the minimum and maximum days
        for (auto b : bloomDay) {
            high = max(high, b);
            low = min(low, b);
        }

        return bs(bloomDay, m, k, low, high, n);
    }
};
