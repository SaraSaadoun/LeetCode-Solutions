class Solution {
public:
    int n, m;
    vector<vector<int>>memo;
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == n - 1 && col == m - 1)
            return grid[row][col];

        if(row == n || col == m)
            return INT_MAX;

        int& ret = memo[row][col];
        if(~ret)
            return ret;
            
        return ret = grid[row][col] + min(solve(row+1, col, grid), solve(row, col+1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo = vector<vector<int>>(n,vector<int>(m,-1));
        return solve(0, 0, grid);
    }
};