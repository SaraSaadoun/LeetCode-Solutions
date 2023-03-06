class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int mx = arr[n - 1];
        int idx = 0, missingNo = 0;
        for(int i = 1; i < mx; ++i){
            if(arr[idx] == i)
                ++idx;
            
            else
                missingNo++;
            
            if(missingNo == k)
                return i;
        }
        
        return mx + k - missingNo;
    }
};