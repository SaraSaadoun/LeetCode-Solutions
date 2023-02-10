class Solution {
public:
    const int OO = INT_MAX;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n;
    bool valid(int i, int j){
        return i>=0 && j>=0 && i<n && j<n;
    }

    int maxDistance(vector<vector<int>>& grid) {
        //Multi source BFS
        queue <pair<int, int>> q;

        n = grid.size();
        int dist[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = OO;
                if(grid[i][j]){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            auto [i, j] = q.front();
            // int i =p.first, j = p.second;

            q.pop();
            
            for(int k = 0; k < 4; ++k){
                int x = i + dx[k];
                int y = j + dy[k];
                if(valid(x, y) && grid[x][y] == 0 && dist[i][j]+1 < dist[x][y]){
                    dist[x][y] = 1 + dist[i][j];
                    q.push({x, y});
                }
            }
            
        }
        int mx = -1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(dist[i][j] != OO && dist[i][j])
                mx = max(mx, dist[i][j]);
            }
        }
        return mx;

    }
};