#define N 100009

class Solution {
public:
    bool vis[N];
    int ans = INT_MAX;
    void dfs(int node, int n, vector<vector<pair<int, int>>>& adj) {
        if(vis[node])
            return;
        vis[node] = true;
        
        for(auto p : adj[node]) {
            int& next_node = p.first;
            int& score = p.second;

            ans = min(ans, score);

            dfs(next_node, n, adj);
        }
        
    }
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(N);
        for(auto road: roads) {
            int &x = road[0];
            int &y = road[1];
            int &score = road[2];
            
            adj[x].push_back({y, score});
            adj[y].push_back({x, score});
        }
        dfs(1, n, adj);   
        return ans;  
    }
};
