class Solution {
public:
    bool vis[100009];
    int dfs(int node, vector<vector<int>>& adj) {
        vis[node] = true;
        int nodes = 1;
        for(auto nxt_node: adj[node]) {
            if(!vis[nxt_node]){
                nodes += dfs(nxt_node, adj);
            }
                
        }
        return nodes;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        //count all pairs
        //count edges
        vector<vector<int>> adj(100009);
        int m = edges.size();
        for(int i = 0; i < m; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long remainingNodes = n;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                int componentNodesNo = dfs(i, adj);
                ans += (componentNodesNo) * (remainingNodes - componentNodesNo);
                remainingNodes -= componentNodesNo;
            }
        }
        return ans;
    }
};