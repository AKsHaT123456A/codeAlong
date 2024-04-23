class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk;
        for (int i = 0; i < a.size(); i++) {
            if (stk.empty() || a[i] > 0)
                stk.push(a[i]);
            else {
                while (!stk.empty() && stk.top() > 0 && stk.top() <abs(a[i]))
                    stk.pop();
                if(!stk.empty() && stk.top()==abs(a[i]))stk.pop();
                else{

                if (stk.empty() || stk.top() < 0)
                    stk.push(a[i]);
                }
            }
        }
        int n = stk.size();
        vector<int> ans(n);
        for (int i = 0; !stk.empty(); i++) {
            ans[i] = stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};