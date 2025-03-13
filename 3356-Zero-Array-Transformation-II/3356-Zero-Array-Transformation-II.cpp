class Solution {
public:
    bool couldBeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector <int> pre(n + 1, 0);
        for (int i = 0; i < k; ++i) {
            int &l = queries[i][0], &r = queries[i][1], &val = queries[i][2];
            pre[l] += val;
            pre[r + 1] -= val;
        }
        for(int i = 0; i < n; ++i) {
            pre[i + 1] += pre[i];
            if(nums[i] > pre[i])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int l = 0, r = m, mid, ans = -1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if (couldBeZero(nums, queries, mid)) {
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