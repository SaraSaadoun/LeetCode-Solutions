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

// another solution :

// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
        
//         int n = nums.size();
//         long long ans = 0, zerosNo = 0;
        
//         for (int i = 0; i < n; ++i) {
//             if(nums[i] == 0) {
//                 ++zerosNo;
//             }
//             else {
//                 ans += zerosNo * (zerosNo + 1) / 2;
//                 zerosNo = 0;
//             }
//         }
//         ans += zerosNo * (zerosNo + 1) / 2;

//         return ans;
//     }
// };