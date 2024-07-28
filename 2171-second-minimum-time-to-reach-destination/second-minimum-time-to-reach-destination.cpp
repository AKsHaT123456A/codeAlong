class Solution {
public:
    int bfs(vector<int> adj[], int time, int change, int n){
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        dist1[1] = 0; 
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        
        while(!q.empty() && dist2[n] == INT_MAX){
            int node = q.front().second, currentDist = q.front().first;
            q.pop();
            if((currentDist/change)%2 == 1){
                currentDist += change - currentDist%change;
            }

            for(auto it: adj[node]){
                if(dist1[it] > currentDist + time){
                    dist1[it] = currentDist + time;
                    q.emplace(dist1[it], it);
                }else if(dist2[it] > currentDist + time && currentDist + time != dist1[it]){
                    dist2[it] = currentDist + time;
                    q.emplace(dist2[it], it);
                }
            }
        }
        return dist2[n];
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> graph[n + 1];
        
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
      
        return bfs(graph, time, change, n);
    }
};