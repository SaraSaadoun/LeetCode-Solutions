class Solution {
public:
    int solve(int time, int i, int n, vector<int>& satisfaction, vector<vector<int>>& memo) {
        if(i == n)
            return 0;
        
        int& ret = memo[i][time];
        if(~ret)
            return ret;
        ret = -INT_MAX;
        
        if(satisfaction[i] < 0) {
            ret = solve(time, i+1, n, satisfaction, memo);
            ret = max(ret, satisfaction[i] * time + solve(time+1, i+1, n, satisfaction, memo));
        }
        else {
            ret = satisfaction[i] * time + solve(time+1, i+1, n, satisfaction, memo);
        }
        
        return ret;
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>memo(509, vector<int>(509, -1));
        //if neg take it or discard it, if pos or zero take it
        return solve(1, 0, satisfaction.size(), satisfaction, memo);
    }
};