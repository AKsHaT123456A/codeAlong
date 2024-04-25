class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> order;
        string ans = "";
        for (auto ch : num) {
            while (!order.empty() && k && order.top() > ch) {
                order.pop();
                k--;
            }
            if (!order.empty()||ch!='0'){
                order.push(ch);
            }
        }
        while(!order.empty()&&k){
            order.pop();
            k--;
        }
        if(order.empty())return "0";
        while(!order.empty()){
            ans+=order.top();
            order.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};