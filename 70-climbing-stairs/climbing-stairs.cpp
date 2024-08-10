class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int  prev2=1;
        int curri=0;
        if(n==1)return 1;
        if(n==2)return 2;
        for (int i = 2; i<=n; i++) {
            curri=prev+prev2;
            prev2=prev;
            prev=curri;
        }
        return curri;
    }
};