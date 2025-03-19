class Solution {
public:
    void flip(vector<int>&nums, int& i) {
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int oper = 0;
        for(int i = 0; i < n - 2; ++i) {
            if(nums[i] == 1) continue;

            flip(nums, i);
            ++oper;
        }
        if(nums[n - 1] == nums[n - 2] && nums[n - 2] == nums[n - 3])
            return oper;
        return -1;

    }
};