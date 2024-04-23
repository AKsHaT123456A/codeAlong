class Solution {
private:
    vector<int> nextSmall(vector<int>& heights, int n) {
        stack<int> stk;
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            stk.empty() ? v[i] = -1 : v[i] = stk.top();
            stk.push(i);
        }
        return v;
    }
    vector<int> prevSmall(vector<int>& heights, int n) {
        stack<int> stk;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            stk.empty() ? v[i] = -1 : v[i] = stk.top();
            stk.push(i);
        }
        return v;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        vector<int> right = nextSmall(heights, n);
        vector<int> left = prevSmall(heights, n);
        for (int i = 0; i < n; i++) {
            if (right[i] == -1)right[i]=n;
            int l = heights[i];
            int b = right[i]-left[i]-1;
            maxArea = max(maxArea, l*b);
        }
        return maxArea;
    }
};