class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& piles,vector<vector<int>>& memo) {
        //no more piles?
        if(i >= piles.size() || k == 0)
            return 0;

        int& ret = memo[i][k];

        if(~ret)
            return ret;

        //don't take any from this pile
        ret = solve(i + 1, k, piles, memo);
        
        int takenCoins = 0, m = piles[i].size();
        // try take j coins from this pile
        for(int j = 0; j < min(m, k); ++j) {
            takenCoins += piles[i][j];
            ret = max(ret, takenCoins + solve(i + 1, k - j - 1, piles, memo));
        }
        return ret;

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>memo(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, piles, memo);
    }
};