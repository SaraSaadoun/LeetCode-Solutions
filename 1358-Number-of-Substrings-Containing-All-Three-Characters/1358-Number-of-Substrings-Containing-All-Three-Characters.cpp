class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        int l = 0, r = 0;
        unordered_map <char, int> mp;
        while (r < n) {
            ++mp[s[r]];
            while (mp.size() == 3) {
                ans += n - r;
                --mp[s[l]];
                if(mp[s[l]] == 0) mp.erase(s[l]);
                ++l;
            }
            ++r;
        }
        return ans;
    }
};