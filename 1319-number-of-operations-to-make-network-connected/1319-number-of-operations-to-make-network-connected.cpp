class Solution {
public:
    int vis[100009];
    void dfs(int computer, vector<vector<int>>& adj) {
        if(vis[computer])
            return;
        vis[computer] = true;
        for(auto c: adj[computer]) {
            dfs(c, adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //think of it as components of networks 
        //you need at least components - 1 cable to connect all of them
        if(connections.size() < n - 1) 
            return -1;        
        vector<vector<int>>adj(100009);
        int m = connections.size();
        for(int i = 0; i < m; ++i) {
            int &a = connections[i][0];
            int &b = connections[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, adj);
                ++components;
            }
        }
        return components - 1;
    }
};