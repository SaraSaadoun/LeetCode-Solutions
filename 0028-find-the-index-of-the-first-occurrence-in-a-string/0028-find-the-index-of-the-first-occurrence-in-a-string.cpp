class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        
        if(needle == haystack) 
            return 0;
        if(haystack.size() < needle.size())
            return -1;

        
        string s = "";
        int i = 0;
        for(; i < n; ++ i){
            s += haystack[i]; 
        }

        for(; i < m; ++i){ 
            if(s == needle)
                return i - n;

            s = s.substr(1);
            s += haystack[i];
        }
        if(s == needle)
            return i - n;
        
       
        return -1;
    }
};