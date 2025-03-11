class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int l = 0, r = 1;
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        
        int n = colors.size();
        while(r < n) {
            if (colors[r] != colors[r - 1]){
                if (r - l == k) ++l;
                ++r;
                // optimization: we can remove nested if here
            } 
            else l = r, ++r;
            
            if(r - l == k) ++ans;
        }
        return ans;
    }
};