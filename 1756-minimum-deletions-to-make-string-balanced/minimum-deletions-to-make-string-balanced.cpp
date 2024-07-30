class Solution {
public:
int minimumDeletions(string s) {
        stack<char> st;
        int n =s.size();
        int res = 0;
        reverse(s.begin(),s.end());
        for(int i =0; i<n; i++){
            char c = s[i];
            if(!st.empty() && st.top() < c){
                res++;
                st.pop();
            }else{
                st.push(c);
            }
        }
        
        return res;
    }
};