class Solution {
public:
    long long tripsNo(vector<int>& time, long long givenTime){
        long long trips = 0;
        for(auto t : time){
            trips += givenTime / t;
        }
        return trips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mn = *min_element(time.begin(), time.end());
        
        long long l = 1, r = 1LL * mn * totalTrips, mid = 0;
        long long ans = 0;
        
        while(l <= r){
            mid = l + (r - l) / 2;
            
            if(tripsNo(time, mid) >= totalTrips){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            
        }

        return ans;
    }
};