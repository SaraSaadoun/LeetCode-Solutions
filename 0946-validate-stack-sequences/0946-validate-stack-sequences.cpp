class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 1, j = 0, n = pushed.size();
        
        stack<int> st;
        st.push(pushed[0]);
        
        while(i < n) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j; 
            }
            else {
                st.push(pushed[i]);
                ++i;
            }
        }
        
        while(!st.empty() && st.top() == popped[j]) {
            st.pop();
            ++j;
        }
        
        return st.empty();
    }
};