class Solution {
    static bool comp(int a,int b)
    {
        return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        int zero=0;
        int n=nums.size();
        for(auto num:nums){
        ans+=to_string(num);
        if(num==0)zero++;}
        if(zero==n)return "0";
        return ans;
    }
};