class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        int n = nums.size();
        for (int &num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for(int &x: freq) {
            if (x&1) {
                return false;
            }
        }
        return true;
    }
};