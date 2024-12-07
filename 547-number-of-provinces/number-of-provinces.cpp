class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // Adjacency list representation
        vector<int> vis(n, 0);      // Visited array
        // Construct adjacency list from isConnected matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int province = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If the node is not visited
                province++;
                dfs(i, vis, adj); // Perform DFS
            }
        }
        return province;
    }
};
