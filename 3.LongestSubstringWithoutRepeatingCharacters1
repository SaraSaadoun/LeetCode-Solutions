/*https://leetcode.com/problems/longest-substring-without-repeating-characters/description/*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;

        int n = s.size(), ansSoFar = 1, ans = 1;
        queue<char>q;
        q.push(s[0]);
        set<char>st;
        st.insert(s[0]);

        for(int i=1; i<n; ++i){
            
            if(!st.empty() && st.find(s[i])!=st.end()){
                while(!q.empty() &&q.front()!=s[i]){
                    st.erase(q.front());
                    q.pop();
                }
                while(!q.empty() && q.front()==s[i]){
                    q.pop();
                }
                q.push(s[i]);
                ans = q.size();
            }
            else{
                q.push(s[i]);
                st.insert(s[i]);
                ans = q.size();
            }
            ansSoFar = max(ans, ansSoFar);

        }
        return ansSoFar;
    }//"abcabcd ef19bb"

};
