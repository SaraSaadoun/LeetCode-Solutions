class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int n= prices.size();
        int mn = prices[0], mx = 0;
        for(int i=1; i<n; ++i){
            if(prices[i]>mn){
                mx = max(mx, prices[i]-mn);
            }
            mn = min(mn, prices[i]);
        }
        return mx;
        
    }
};
/* another solution : 
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
*/