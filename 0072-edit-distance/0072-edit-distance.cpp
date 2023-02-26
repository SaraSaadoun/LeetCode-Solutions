class Solution {
public:
    map<pair<string, string>, int> mp;
    int minDistance(string word1, string word2) {
        if(word1 == word2)
            return 0;
        if(word1.size() == 0 )
            return word2.size();
        if(word2.size() == 0)
            return word1.size();

        if(mp[{word1, word2}])
            return mp[{word1, word2}];
        
        if(word1[0] == word2[0]){
            
            mp[{word1, word2}] = minDistance(word1.substr(1), word2.substr(1));

        }
        else{
            string tmp = word1;
            tmp[0] = word2[0];
            int choice3 = minDistance(tmp, word2);
            
            int choice1 = minDistance(word2.substr(0,1) + word1, word2);
            int choice2 = minDistance(word1.substr(1), word2);
            
            mp[{word1, word2}] =  1 + min(choice1, min(choice2, choice3));

        }
        return mp[{word1, word2}];   
    }
};