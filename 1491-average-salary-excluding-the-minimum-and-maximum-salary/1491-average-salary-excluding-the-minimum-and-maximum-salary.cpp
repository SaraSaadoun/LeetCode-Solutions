class Solution {
public:
    pair<int, int> get_min_max(vector<int>& salary, int& n) {
        int mn = salary[0], mx = salary[0];
        
        for(int i = 1; i < n; ++i) {
            mn = min(mn, salary[i]);
            mx = max(mx, salary[i]);
        }
        
        return {mn, mx};
    }
    double average(vector<int>& salary) {
        int n = salary.size();

        auto [mn, mx] = get_min_max(salary, n);

        double ans = 0;
        for (int i = 0; i < n; ++i) {
            if (salary[i] != mn && salary[i] != mx) {
                ans += salary[i];
            }
        }
        ans /= (n - 2);
        
        return ans;
    }
};