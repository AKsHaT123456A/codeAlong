class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans(2);
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        while(k--){
            auto front = pq.top();
            pq.pop();
            ans[0]=front.second.first;
            ans[1]=front.second.second;
        }
        return ans;
    }
};