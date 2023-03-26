class Solution {
public:
    #define N 100009
    int cycleLength = 0;
    //timer = num > 1 if vis in this component
        //timer = -1 if never vis
        //timer = 0 if vis in other compnent
    int dfs(int node, vector<int>& edges, vector<int>&timer, int time) { 
        if(node == -1)
            return -1;
        
        if(timer[node] > 0){
            return time - timer[node];
        }
            
        if(timer[node] == 0)
            return -1;
        
        timer[node] = time;
        int ret = dfs(edges[node], edges, timer, time+1);
        timer[node] = 0;
        return ret;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int longestCycle = -1;
        vector<int>timer(n, -1);
        set<int>st;
        for(int i = 0; i<n; ++i){
            if(edges[i] != -1)
                st.insert(edges[i]);
        }
        

        for(auto i : st) {
            if(timer[i] == -1) {
                cycleLength = dfs(i, edges, timer, 1);
                longestCycle = max(cycleLength, longestCycle);
                cycleLength = -1;
            }
        }
        return longestCycle;
    }
};