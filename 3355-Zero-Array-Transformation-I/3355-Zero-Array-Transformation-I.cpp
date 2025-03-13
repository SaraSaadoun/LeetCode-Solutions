class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector <int> pre(n + 1, 0);
        for (auto &query: queries) {
            int &l = query[0], &r = query[1];
            ++pre[l], --pre[r + 1];
        }

        for (int i = 0; i < n; ++i) {
            pre[i + 1] += pre[i];
            if(nums[i] > pre[i])
                return false;
        }
        return true;
    }
};