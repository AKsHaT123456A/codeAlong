class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        std::stack<int> stk;
        std::vector<int> left(n), right(n);

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            left[i] = (stk.empty() ? i + 1 : i - stk.top());
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            right[i] = (stk.empty() ? n - i : stk.top() - i);
            stk.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        
        return sum;
    }
};