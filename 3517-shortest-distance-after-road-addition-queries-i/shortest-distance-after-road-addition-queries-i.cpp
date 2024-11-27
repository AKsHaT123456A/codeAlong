class Solution {
public:
    typedef pair<int, int> pii;
    int dijkstra(int n, unordered_map<int, vector<pii>>& adj, int src, int dest) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<pii>> adj;
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back({i + 1, 1});
        }
        vector<int> ans;
        for (auto& it : queries) {
            int u = it[0], v = it[1];
            adj[u].push_back({v, 1});
            ans.push_back(dijkstra(n, adj, 0, n - 1));
        }

        return ans;
    }
};