class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e';
    }

    long long countOfSubstrings(string word, int k) {

        // get next consonant index
        int n = word.size();
        vector<int> next_con(n, n);
        int next_con_idx = n;
        for (int i = n - 1; i >= 0; --i) {
            
            next_con[i] = next_con_idx;

            if (!isVowel(word[i]))
                next_con_idx = i;
        }
        
        unordered_map <char, int> vowels_freq;
        int cons = 0;
        int l = 0, r = 0;
        long long ans = 0;

        while (r < n) {
            // freq
            if (isVowel(word[r])) {
                ++vowels_freq[word[r]];
            }
            else {
                ++cons;
            }

            while(cons > k) {
                if( isVowel(word[l]) ) {
                    --vowels_freq[ word[l] ];
                    if(vowels_freq[word[l]] == 0) {
                        vowels_freq.erase(word[l]);
                    }
                }
                else {
                    --cons;
                }
                ++l;
            }

            while(vowels_freq.size() >= 5 && cons == k) {
                ans += next_con[r] - r; 
                
                if(isVowel(word[l])) {
                    --vowels_freq[word[l]];
                    if (vowels_freq[word[l]] == 0) 
                        vowels_freq.erase(word[l]);
                }
                else {
                    --cons;
                }
                ++l;
            }
            ++r;
        }        
        return ans;
    }
};