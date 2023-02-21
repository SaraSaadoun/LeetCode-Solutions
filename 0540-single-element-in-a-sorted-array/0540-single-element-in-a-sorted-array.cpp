class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //another solution is commented below
        int n = nums.size();
        int l = 0, r = n - 1, mid = 0, ans = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            
            //make sure the idx is even
            if(mid&1)
                --mid;
            
            if(mid >= n - 1 || nums[mid] != nums[mid+1]){
                ans = nums[mid];
                r = mid - 1;
            }
            else{
                l = mid + 2;
            }
            
        }
        return ans;
    }
};
/* 
        int n = nums.size();
        int l = 0, r = n / 2, mid = 0, ans = 0;
        while(l <= r){
            mid = l + (r - l) / 2;

            int i = mid * 2;

            // 1 1 2 3 3 4 4
            // t   f   f   f => get the first false
            
            //compare the even idx with the following one
            //if not equal =>then the result on the left part
            //else => the result on the right one
            
            if(i >= n - 1 || nums[i] != nums[i + 1]){
                ans = nums[i];
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            

        }
        return ans;
        */