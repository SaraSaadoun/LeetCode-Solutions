class Solution {
public:
    
    vector<int> sortArray(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN, n = nums.size();
        unordered_map<int, int>mp;
        
        for(int i = 0; i < n; ++i){
            mp[nums[i]]++;
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        
        vector<int>ans;
        for(int i = mn; i<=mx; ++i){
            while(mp[i]--)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};

//another solution: merge sort:
/*
class Solution {
public:
    
    vector<int> solve(int st, int end, vector<int>& nums){
        if(st == end-1)
            return vector<int>(1, nums[st]);

        int mid = st + (end - st) / 2;
        vector<int> left = solve(st, mid, nums);
        vector<int> right = solve(mid, end, nums);

        vector<int> ans;
        int l = 0, r = 0;
        int n = left.size(), m = right.size();

        while(l < n && r < m){
            if(left[l] < right[r])
                ans.push_back(left[l++]);
            else
                ans.push_back(right[r++]);

        }
        while(l < n)
            ans.push_back(left[l++]);
        while(r < m)
            ans.push_back(right[r++]);
            
        return ans;

    }
    vector<int> sortArray(vector<int>& nums) {
        
        
        return solve(0, nums.size(), nums);
        
    }
};

*/