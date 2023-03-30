class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool isScramble(string s1, string s2) {        
        int n = s1.size();
        
        //if both string are not equal in size
        if(s2.size() != n)
            return false;
        
        //if both string are equal
        if(s1 == s2)
         return true;   
        
        string key = s1+" "+s2;
        
		//check if this problem has already been solved
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        for(int i = 1 ; i <= n - 1; i++){
            // Check if s1[0:i] is a scramble of s2[n-i:i] and s1[i:n] is a scramble of s2[0:n-i]
            if(isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return mp[key] = true;
            
            // Check if s1[0:i] is a scramble of s2[0:i] and s1[i:n] is a scramble of s2[i:n]
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return mp[key] = true;
        }

        
        
        return mp[key] = false;
        
    }
};