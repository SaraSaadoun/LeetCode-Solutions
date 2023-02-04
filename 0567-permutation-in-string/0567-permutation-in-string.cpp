//Author: Sara Hamza
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;

        //getting freq of all letters in s1 
        //freq (const) to restore freqCpy later
        int freq[26] = {0}, freqCpy[26] = {0};
        for(int i = 0; i < n; ++i){
            freqCpy[s1[i] - 'a']++;
            freq[s1[i] - 'a']++;
        }

        for(int  i = 0; i <= m - n; ++i){
            //r u any letter of s1?
            if(freq[s2[i] - 'a'] > 0){
                //compare from i to i+n-1
                int j = i, nn = n;
                while(nn && j < m){
                    //not a permutation?
                    if(freqCpy[s2[j] - 'a'] <= 0){
                        break;

                    }
                    //mark that a letter 've been found
                    freqCpy[s2[j++] - 'a']--;
                    --nn;
                }

                //a permutation?
;               if(nn == 0) return true;
                
                //restore freqCpy's values if it is not a permutation
                for(int k = 0; k < 26; ++k)
                    freqCpy[k] = freq[k];
            }
        }
        

        return false;        


    }
};