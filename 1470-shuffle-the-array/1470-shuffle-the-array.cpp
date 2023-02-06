class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans(2*n);
        for(int i = 0; i < n; ++i){
            //even indices
            ans[2*i] = nums[i];
            //odd indices
            ans[2*i+1] = nums[i+n];
        }
        return ans;
    }
};