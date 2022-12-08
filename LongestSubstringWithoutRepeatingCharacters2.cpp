class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;

        int n = s.size(), ansSoFar = 1;
        
        /*
        history of all duplicates - even they are not in the  curr substr - with 
        their position + 1 indicating the start of new valid substr
        */ 
        unordered_map<char, int> mp; 

        int st = 0;
        for(int en=0; en<n; ++en){
            /*
            if a duplicate found => get the sutible start for the curr substr
                if invalid match (meaning that duplicate is not within the curr substr) => same start
                else if valid match 
                meaning that duplicate is within the curr substr)=> advance start to that point mp[]
            */
            if(mp[s[en]] > 0)
                st = max(mp[s[en]], st);
            mp[s[en]] = en+1;
            ansSoFar = max(en - st + 1, ansSoFar);

        }
        return ansSoFar;
    }

};
