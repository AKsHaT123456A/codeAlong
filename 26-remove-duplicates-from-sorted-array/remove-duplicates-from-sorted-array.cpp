class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> omp;
        for(int num:nums){
            omp[num]++;
        }
        int i=0;
        for(auto it:omp){
            cout<<it.second<<endl;
            nums[i]=it.first;
            i++;
        }
        return i;
    }
};