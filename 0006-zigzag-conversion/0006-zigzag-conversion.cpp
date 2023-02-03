class Solution {
public:
    string convert(string s, int numRows) {
        /*
        deduce a pattern to get all letters of the same row at one shot
        
        ex:
        
        0       6                       
        1     5   7           ...   
        2  4        8   10              
        3             9
        distance between consecutive 0s = 0, 6, 12, ... inc by(2*4 - 2*0) 
                                     1s = 1, 5, 7, ...  inc by(2*4 - 2*1) then 2*1 then (2*4 - 2*1) ...
                                     2s = 2, 4, 8, 10   inc by(2*4 - 2*2) then 2*2 ..
                                     3s = 3, 9, ..      inc by(2*4 - 2*3) then 2*3 ..
                                     
                                     iths = 2*n - 2*i then 2*i
                                     
        so, to get all letters of the i-th row
 
        1. add this amount "2n-2i" to the current idx (idx -> row no initially)
        2. then add this amount 2i to it  repeatedly till reaching the end of s

        note: if it is the 0-th or (n-1)-th row 
              the formula gives 0 for either 2n-2i or 2i
              "meaning that you will count the same letter twice"
              so, ignore one of them
        */
        
        string ans = "";
        int inc = 2 * numRows - 2, n = s.size();
        int idx = 0; // iterator for all of the letters of the i-th row 
        
        
        if(numRows == n || numRows == 1) //already in zigzag form (single column)
            return s;
            
        for(int i = 0; i < numRows; ++i){
            idx = i;
            //check for handling case of getting increment by 0
            if(i == 0 || i == numRows - 1){
                while(idx < n){
                    ans += s[idx];
                    idx += inc;
                }
            }
            else{
                bool flag = 1;
                while(idx < n){
                    ans += s[idx];
                    idx += (flag ? inc - i*2 : i*2) ;    
                    flag ^= 1; //flip
                }
            }
            
        }
        return ans;
    }
};