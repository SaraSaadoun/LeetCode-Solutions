class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //maping their language to ours
        map <char, char> mp;
        
        for(int i=0; i<26; ++i){
            mp[order[i]] = i+'a';
        }
        
        int n = (int)words.size();
        
        for(int i=0; i<n; ++i){
            int m = words[i].size();
            for(int j=0; j<m; ++j){
                words[i][j] = mp[words[i][j]];
            }
        }

        //get the sorted words
        vector <string> sorted_words = words;
        sort(sorted_words.begin(), sorted_words.end());

        //compare
        for(int i=0; i<n; ++i){
            if(sorted_words[i] != words[i])
                return false;
        }

        return true;
        
    }
};