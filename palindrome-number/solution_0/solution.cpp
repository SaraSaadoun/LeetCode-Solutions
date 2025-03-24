class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        cout << s << '\n';
        while(l < r) {
            if(s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
};