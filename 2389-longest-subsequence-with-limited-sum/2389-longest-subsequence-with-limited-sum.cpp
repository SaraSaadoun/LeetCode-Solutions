class Solution {
public:

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int sum = 0, preSum[n];
        
        for(int i=0; i<n; ++i){
            sum += nums[i];
            preSum[i] = sum;
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; ++i){
            //binary_search
            int l = 0, r = n-1, mid = 0, res = -1;
            while(l<=r){
                mid = l + (r - l) / 2;
                if(preSum[mid] <= queries[i]){
                    res = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            ans[i] = res+1;
        }
        
        return ans;
    }
    
};