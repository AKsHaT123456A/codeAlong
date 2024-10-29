class Solution {
public:
    bool isValid(string s) {
        int s_len = s.length();
        if (s_len % 2 != 0) return false;
        
        stack<char> st;
        for (int i = 0; i < s_len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else if (st.top() =='(' && s[i] != ')' || st.top() =='{' && s[i] != '}'
                   || (st.top() =='[' && s[i] != ']')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};