class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
           vector<vector<int>> adj(numCourses);
       for (const auto& pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            // cout<<adj[node]<<endl;
            for (auto it : adj[node]) {
                cout<<it<<endl;
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] != 0)
                return false;
        }
        return true;
    }
};