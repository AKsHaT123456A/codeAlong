class Solution {
public:
    static bool cmp(int a , int b){
        return a<b;
    }
   vector<int> eventualSafeNodes(vector<vector<int>>& G) {
    int N = G.size();
    vector<vector<int>> R(N);
    vector<int> outdegree(N), safe(N), ans;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        for (int v : G[i]) {
            R[v].push_back(i);
        }
        outdegree[i] = G[i].size();
        if (outdegree[i] == 0) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : R[u]) {
            if (--outdegree[v] == 0) q.push(v);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    return ans;
}
};