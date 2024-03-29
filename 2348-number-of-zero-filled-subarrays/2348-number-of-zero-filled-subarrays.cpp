// another soluton : https://leetcode.com/submissions/detail/919317062/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0, zerosNo = 0;
        int st = 0, en = 0;
        while(en < n) {
            if(nums[en] != 0) {
                st = en + 1;
            }
            ans += en - st + 1;
            ++en;
        }
        return ans;
    }
};

