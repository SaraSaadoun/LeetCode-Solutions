//Author: Sara Hamza
class Solution {
public:
    string convert(string s, int numRows) {

        int n = s.size(),  c = 0, dir = 1;
        string ans = "", row[numRows];
        
        if(numRows == n || numRows == 1) //already in zigzag form (column || row)
            return s;
        
        for(int i=0; i<n; ++i){
            row[c] += s[i]; //building rows
            
            
            if(c == numRows-1) dir = -1; //dec direction
            if(c == 0) dir = 1;          //inc direction
            
            c += dir;
        }
        
        //concatenation
        for(int i=0; i<numRows; ++i){
            ans += row[i];
        }
       
        return ans;
    }
};