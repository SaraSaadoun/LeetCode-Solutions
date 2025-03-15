class Solution {
public:
    bool canUse(vector<int>& candies, long long k, int reqCandiesNo) {
        long long n = candies.size();
        long long childrenNo = 0;
        for(int &candy: candies) {
            childrenNo += candy / reqCandiesNo;
        }
        return childrenNo >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandy = 0;
        for(int &candy: candies) {
            maxCandy = max(candy, maxCandy);
        }
        int l = 0, r = maxCandy, mid, ans = 0;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mid == 0 || canUse(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};