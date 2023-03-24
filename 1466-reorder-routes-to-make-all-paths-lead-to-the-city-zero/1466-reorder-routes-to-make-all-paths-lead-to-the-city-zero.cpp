class Solution {
public:
    int vis[50009];
    int dfs(int node, vector<vector<int>>&adj) {
    
        int changed = 0;
        for(auto nxt_node : adj[node]) {
            if(!vis[abs(nxt_node)]) {
                vis[abs(nxt_node)] = true;
                changed += (nxt_node > 0) + dfs(abs(nxt_node), adj);
            }
        }
        return changed;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        //reverse problem -> from 0 to all cities
        vector<vector<int>>adj(50009);
        int m = connections.size();
        vector<int>cities(1, 0);
        for(int i = 0; i < m; ++i) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]); 
        }
        
        return dfs(0, adj);
        
    }
};