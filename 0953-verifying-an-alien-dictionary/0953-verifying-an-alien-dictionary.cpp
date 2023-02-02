class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //maping their language to ours
        unordered_map <char, char> mp;
        
        for(int i=0; i<26; ++i){
            mp[order[i]] = i+'a';
        }
        
        
        int m = (int)words.size();
        
        //sz of the longest word
        int n = (int)words[0].size();
        
        for(int i=1; i<m; ++i){
            if(words[i].size() > n)
                n = words[i].size(); 
        }

        for(int i=0; i<n; ++i){
            char prev = 'a'-1; 
            bool equal = 0;
            bool firstTime = 1;

            //check at the i-th position
            for(int j=0; j<m; ++j){
                if(i >= words[j].size()) {
                    if(j != 0 && words[j].size() < words[j-1].size())
                        return false;
                    continue;
                }


                if(mp[words[j][i]] > prev){
                    prev = mp[words[j][i]];
                }
                else if(mp[words[j][i]] == prev){
                    equal = 1;
                }
                else{
                    return false;
                }
            }
            if(!equal) {
                return true;
            }
            
        }
        return true;
    }
};