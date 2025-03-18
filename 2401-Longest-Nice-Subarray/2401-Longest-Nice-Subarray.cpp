class Solution {
public:
    bool canAdd(long long num, long long freq) {
        for(int j = 0; j < 32; ++j) {
            if (((freq >> j) & 1) && ((num >> j) & 1)) {
                return false;
            } 
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        long long freq = 0, ans = 1, window = 0;
        bool flag = false;
        int l = 0, r = 0;
        while(r < n) {
            // try add nums[r]
            if(canAdd(nums[r], freq)) {
                freq += nums[r];
                ans = max(ans, r - l + 1LL);
                ++r;
                continue;
            }
            // try rem from left side till it is valid again
            while (l<r && !canAdd(nums[r], freq)) {
                freq -= nums[l];
                ++l;
            }
            freq += nums[r];
            ans = max(ans, r - l + 1LL);
            ++r;

        }
        return ans;
    }
};