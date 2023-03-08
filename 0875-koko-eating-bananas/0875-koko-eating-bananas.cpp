class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // maximum hours needed is to take each pile at one hr
        //so, maximum k is to eat max(piles) at 1 hour
        long long lo = 1, hi = maximum(piles), mid = 0;
        long long ans = 0;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            long long hoursTaken = calculateHours(piles, mid);

            if(hoursTaken <= h) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;     
        }
        return ans;
    }
    long long calculateHours(vector<int>& piles,  long long givenSpeed) {
        long long ans = 0;
        for(auto p : piles) {
            ans += (p + givenSpeed - 1) / givenSpeed;
        }
        return ans;
    }
    long long maximum(vector<int>& piles) {
        return *max_element(piles.begin(), piles.end());
    }
};