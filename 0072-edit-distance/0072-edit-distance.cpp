class Solution {
public:
    int memo[509][509];
    int n, m;
    int minDist(int i, int j, string word1, string word2){
        
      
        if(i == n)
            return m - j;
        if(j == m)
            return n - i;

        int &ret = memo[i][j];

        if(~ret)
            return ret;

        if(word1[i] == word2[j])
            return ret = minDist(i+1, j+1, word1, word2);
        
        return ret = 1 + min({
            minDist(i+1, j, word1, word2), //delete
            minDist(i, j+1, word1, word2), //insert
            minDist(i+1, j+1, word1, word2)}); //replace
        
    }
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        memset(memo, -1, sizeof memo);

        return minDist(0, 0, word1, word2);  
    }
};