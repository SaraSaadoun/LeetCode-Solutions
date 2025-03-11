class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        
        // Stores the index of the next consonant for each position
        vector<int> nextConsonant(n, n);
        int nextConsonantIndex = n;
        
        // Populate next consonant indices from right to left
        for (int i = n - 1; i >= 0; --i) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }
        
        unordered_map<char, int> vowelFrequency;
        int consonantCount = 0;
        int left = 0, right = 0;
        long long ans = 0;

        while (right < n) {
            // Update frequency map and consonant count
            if (isVowel(word[right])) {
                ++vowelFrequency[word[right]];
            } else {
                ++consonantCount;
            }

            // If the substring is invalid (too many consonants), shrink from the left
            while (consonantCount > k) {
                if (isVowel(word[left])) {
                    --vowelFrequency[word[left]];
                    if (vowelFrequency[word[left]] == 0) {
                        vowelFrequency.erase(word[left]);
                    }
                } else {
                    --consonantCount;
                }
                ++left;
            }

            // If the substring is valid, count the number of valid substrings
            while (vowelFrequency.size() >= 5 && consonantCount == k) {
                // Count substrings that remain valid until the next consonant
                ans += nextConsonant[right] - right;
                
                // Move the left boundary to explore other valid substrings
                if (isVowel(word[left])) {
                    --vowelFrequency[word[left]];
                    if (vowelFrequency[word[left]] == 0) {
                        vowelFrequency.erase(word[left]);
                    }
                } else {
                    --consonantCount;
                }
                ++left;
            }

            // Expand the window to the right
            ++right;
        }        

        return ans;
    }
};
