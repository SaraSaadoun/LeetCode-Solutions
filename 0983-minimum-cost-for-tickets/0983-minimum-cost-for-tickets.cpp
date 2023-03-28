class Solution {
public:
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
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int>daysSet;
        for(auto d : days)
            daysSet.insert(d);
        
        vector<int>memo(366, -1);
        
        return solve(1, daysSet, costs, memo);
    }
};