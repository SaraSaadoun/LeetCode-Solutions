class Solution {
public:

    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int mx = 0, mn = 0;
        for(auto &weight: weights){
            mn = max(mn, weight);
            mx += weight;
        }
        
        return binary_search(mn, mx, days, weights);

    }
    int binary_search(int l, int r, int days, vector<int>& weights){
        int mid = 0, ans = 0;
        while(l <= r){
            mid = l + (r - l)/2;
            
            if(noOfDaysNeeded(mid, weights) > days){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
    int noOfDaysNeeded(int mxCapacity, vector<int>& weights){
        int currCapacity = 0, daysNo = 1;
        for(auto &weight: weights){
            if(currCapacity + weight > mxCapacity){
                daysNo++;
                currCapacity = 0;
            }
            currCapacity += weight;
        }
        return daysNo;
    }
};
