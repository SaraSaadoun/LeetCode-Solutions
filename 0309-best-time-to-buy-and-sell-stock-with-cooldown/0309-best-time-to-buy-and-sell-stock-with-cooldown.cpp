class Solution {
public:
    //lastTransaction : {b: 0 , s:1 , c:2}
    int n;
    int inf = -1e9;
    vector<int>price;
    int memo[5009][2][2];
    int max_profit(int i, bool lastTransaction, bool lastCooldown){
        if(i == n) return 0;
        int& ret = memo[i][lastTransaction][lastCooldown];
        if(~ret) return ret;

        else if(lastCooldown){
            if(!lastTransaction){ // buy cooldown then?
                ret = max_profit(i+1, lastTransaction, 1); //cool again
                ret = max(ret, price[i] + max_profit(i+1, 1, 0)); //sell
            }
            else { // buy cooldown then?
                ret = max_profit(i+1, lastTransaction, 1); //cool again
                ret = max(ret, -price[i] + max_profit(i+1, 0, 0)); //sell
            }
        }
        else{
            if(!lastTransaction){//buy then?
                ret = max_profit(i+1, lastTransaction, 1); //cooldown
                ret = max(ret, price[i] + max_profit(i+1, 1, 0)); //sell
            
            }
            else { //sell then?
                ret = max_profit(i+1, lastTransaction, 1); //must cooldown
            }
            
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        price = prices;
        n = prices.size();
        memset(memo, -1, sizeof memo);
        return max_profit(0, 1, 1);
    }
};