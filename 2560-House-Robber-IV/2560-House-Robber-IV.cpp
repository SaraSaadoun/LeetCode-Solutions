class Solution {
public:
    bool possibleTheft(vector<int>& nums, int& k, int& cap) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (nums[i] <= cap) {
                ++cnt;
                ++i;
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = nums[0], mx = nums[0];
        for(int i = 1; i < n; ++i) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int l = mn, r = mx, mid, ans = -1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(possibleTheft(nums, k, mid)) {
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