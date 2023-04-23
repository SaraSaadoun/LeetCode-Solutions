class Solution {
public:
    const int MOD = 1000000007;
    int solve(int st, string& s, int k, vector<int>& memo) {
        // solve(0) -> (solve(1), solve(2), ..)
        // solve(2) ->(solve(3), ...)
        // ..
        int n = s.size();

        if(st == n)
            return 1;
        if(s[st] == '0')
            return 0;

        int& ret = memo[st];
        if(~ret)
            return ret;

        ret = 0;
        long long d = 0;
        for(int en = st; en < n; ++en) {
            //calc (st, st), (st, st+1), .. (st, n-1)
            d = d * 10 + (s[en]-'0');
            if(d > k)
                break;
            // go calc remaining from en+1
            ret = (ret + solve(en + 1, s, k, memo)) % MOD;
        }
        

        return ret;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int>memo(n, -1);
        return solve(0, s, k, memo);
    }
};