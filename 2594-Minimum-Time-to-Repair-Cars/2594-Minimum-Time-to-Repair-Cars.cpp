class Solution {
public:
    bool canBeRepaired(vector<int>& ranks, int cars, long long timeNeeded) {
        int n = ranks.size();
        // t = r * n * n
        // n = sqrt (t / r)
        int noCars = 0;
        for(int i = 0; i < n; ++i) {
            noCars += sqrt(timeNeeded / ranks[i]);
            if(noCars >= cars)
                return true;
        }
        return noCars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18, mid, ans = 0;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(canBeRepaired(ranks, cars, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};