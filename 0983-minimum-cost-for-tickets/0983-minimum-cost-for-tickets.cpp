class Solution {
public:
    //recursive sol
    int solve(int i, set<int>daysSet, vector<int>& costs, vector<int>& memo) {
        if(i > 365)
            return 0;
        
        int& ret = memo[i];
        if(~ret)
            return ret;
        
        if(daysSet.find(i)!=daysSet.end()) {
            int ch1 = costs[0] + solve(i+1, daysSet, costs, memo);
            int ch2 = costs[1] + solve(i+7, daysSet, costs, memo);
            int ch3 = costs[2] + solve(i+30, daysSet, costs, memo);
            ret = min({ch1, ch2, ch3});
        }
        else {
            ret = solve(i+1, daysSet, costs, memo);
        }
        
        return ret;
    }
    //iterative sol
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int n = 365;
        vector<int>dp(n + 1, 0);
        set<int>daysSet;
        for(auto d: days)
            daysSet.insert(d);
        
        for(int i = 1; i <= n; ++i) {
            if(daysSet.find(i) != daysSet.end()) {
                int ch1 = dp[max(i-1, 0)] + costs[0]; 
                int ch2 = dp[max(i-7, 0)] + costs[1];
                int ch3 = dp[max(i-30, 0)] + costs[2];
                dp[i] = min({ch1, ch2, ch3});
            }
            else 
                dp[i] = dp[i-1];
        }
        return dp[n];
    }
};