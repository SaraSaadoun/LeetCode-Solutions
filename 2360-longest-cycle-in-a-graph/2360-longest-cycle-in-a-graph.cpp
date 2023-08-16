class Solution {
public:
    const int N = 1e5+9;
    int timer = 1;
    int dfs(int u, vector<int>& edges,vector<int>&time) {
        if(time[u] > 0) {
            return timer - time[u];
        }
        if(time[u] == 0 || edges[u] == -1)
            return -1;
        
        time[u] = timer++;
       
        int ret = dfs(edges[u], edges, time);
        
        time[u] = 0;
        return ret;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> time(n+1, -1), in(n+1, 0);

        for(int i = 0; i < n; ++i){
            if(edges[i]!=-1)
                in[edges[i]] = 1;
        }
        int mxCycle = -1;
        for(int i = 0; i < n; ++i){
            timer = 1;
            if(in[i] && time[i] == -1)
                mxCycle = max(mxCycle, dfs(i, edges, time));
        }
        return mxCycle;
        
    }
};