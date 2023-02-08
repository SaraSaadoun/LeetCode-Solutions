class Solution {
public:

    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = 0;

        int res = 0;
        while(r < n - 1){
            int far = 0;
            for(int i = l; i <= r; ++i)
                far = max(far, i+nums[i]);
            ++res;
            l = r + 1;
            r = far;
        }
        return res;
        
    }
};