class Solution {
public:

    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // get indices of each value
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; ++i)
            indices[arr[i]].push_back(i);

        
        // BFS
        queue<int> q;
        q.push(0);
        
        int dep = -1;
        int target = arr[n-1];
        
        //avoid time limit
        vector<bool>vis(n+1,0);
        vis[0] = 1;
        
        while(!q.empty()){
            int sz = q.size();
            ++dep;
            while(sz--){
                int i = q.front();
                q.pop();
                vis[i] = 1;
                
                if(i == n-1)
                    return dep;
                //move one step forward
                if(!vis[i+1])
                    q.push(i+1);
                //move one step backward
                if(i && !vis[i-1])
                    q.push(i-1);
                //jump into indices of the same value
                for (auto j : indices[arr[i]]){
                    if(!vis[j])
                        q.push(j);
                }
                //to avoid redundant search
                indices[arr[i]].clear();
                
                
            }
        }
        
        return dep;
    }
};