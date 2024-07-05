class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<=2)return false;
        int i=0,j=1,k=2;
        while(k<arr.size()){
            if(arr[i]%2!=0 && arr[j]%2!=0 && arr[k]%2!=0)return true;
            i++;j++;k++;
        }
        return false;
    }
};