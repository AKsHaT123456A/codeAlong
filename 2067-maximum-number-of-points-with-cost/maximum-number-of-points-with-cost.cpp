class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> tmp(n);
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n; ++j) tmp[j] += points[i][j];
            for(int j = 1 ; j < n ; ++j)tmp[j] = max(tmp[j-1]-1, tmp[j]);
            for(int j = n-2 ; j >= 0; --j) tmp[j] = max(tmp[j+1]-1, tmp[j]);
        }
        return *max_element(begin(tmp),end(tmp));
    }
};