//improved solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;

        int freq[26] = {0}, freq2[26] = {0};

        //build freq of all letters in s1 
        for(int i=0; i<n; ++i) freq[s1[i]-'a']++;

        //build freq2 of 2st sliding window letters in s2 
        //except for the last letter
        int i = 0;
        for(; i<n-1; ++i) freq2[s2[i]-'a']++;


        for(; i<m; ++i){
            //get last letter in freq2
            freq2[s2[i]-'a']++;

            //compare freq of s1 with freq of a substr of s2
            bool flag = 0;
            for(int j=0; j<26; ++j){
                if(freq[j] != freq2[j]){
                    flag = 1;
                    break;
                }
            }
            
            //equal frequences ?  a permutation
            if(flag == 0) return true;

            //get first letter of substr our of freq2
            freq2[s2[i-n+1]-'a']--;
        } 
            

        
        return false;      


    }
};