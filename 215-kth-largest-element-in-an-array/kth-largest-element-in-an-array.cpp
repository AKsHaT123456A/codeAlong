class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto num:nums){
            pq.push(num);
        }
        int l=k-1;
        while(l){
            pq.pop();
            l--;
        }
        return pq.top();
    }
};