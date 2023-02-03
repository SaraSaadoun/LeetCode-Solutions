class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(),  c = 0, dir = 1;
        string ans = "", row[numRows];
        
        if(numRows == n || numRows == 1) 
            return s;
        
        for(int i=0; i<n; ++i){
            row[c] += s[i];
            
            if(c == numRows-1) dir = -1;
            if(c == 0) dir = 1;
            
            c += dir;
        }
        for(int i=0; i<numRows; ++i){
            ans += row[i];
        }
       
        return ans;
    }
};