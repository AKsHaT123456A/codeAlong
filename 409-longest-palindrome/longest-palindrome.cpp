class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        int n=s.length();
        map<char, int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        bool isOdd=false;
        map<char, int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++){
            if(itr->second%2==1){
                isOdd = true;
            }
            ans += (itr->second/2)*2;
        }
        return ans+(isOdd>0?1:0);
    }
};