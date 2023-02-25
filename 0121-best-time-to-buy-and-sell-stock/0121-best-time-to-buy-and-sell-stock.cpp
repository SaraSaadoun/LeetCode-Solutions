class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //mx[i] => the max from i till the end of the array
        vector<int>mx(n, -1);
        // prices : [7,1,5,3,6,4]
        mx[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; --i){
            mx[i] = max(mx[i + 1], prices[i]);
        }
        // mx : [7,6,6,6,6,6]
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, mx[i] - prices[i]);
        }
        return ans;
    }
};
