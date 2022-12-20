class Solution {
public:
    int reverse(int x) {
        int n = x, ans =0;
        int sign = x < 0 ? 1 : 0;
        
        string s = to_string(n);
        if(sign) s = s.substr(1);
        
        //reversing positive x
        std::reverse(s.begin(), s.end());
        
        //checking overflow
        
        string std = sign? "2147483648" : "2147483647";
        
        if(std.size() == s.size()){
            int sz = std.size();
            
            for(int i=0; i<sz; ++i){
                if(s[i] < std[i]) 
                    break;
                if(s[i] == std[i]) 
                    continue;
                else 
                    return 0;
            }
        }
        return sign? -1*stoi(s) : stoi(s);
    }
};