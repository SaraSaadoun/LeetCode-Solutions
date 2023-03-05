class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int, int>mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i=0; i<n; ++i){
            //prefix sum
            sum += nums[i];
            
            //do we have found any subarray prior to this 
            //where if we substracted its sum from the ours
            //gives a new subarray of k as a sum
            // sum - ''?'' = k => '?' = sum - k, have we found any of sum = '?'
            if(mp[sum - k])
                ans += mp[sum - k];
            //we 've found subarray of sum = sum
            mp[sum]++;
            
            
        }
        return ans;
    }
};