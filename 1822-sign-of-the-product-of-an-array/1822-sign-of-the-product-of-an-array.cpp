class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0, zero = 0;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if(nums[i] < 0 )neg++;
            else if (nums[i] == 0) zero++;
        }
        if (zero)
            return 0;
        
        if (neg & 1 )
            return -1;
        return 1;
    }
};