class Solution {
public:

    string simplifyPath(string path) {
        // /home/a/../b//c/..//d
        //1.get stacked tokens 
        // home, a, .., b, c, .. , d
        //toBePopped variable: to keep track of number of directories to be popped


        //iterate for elements in stack:
        //pop it then,
        // if .. :toBePopped++
        //if . :continue
        //else "any directory": if toBePopped -> dec it
        //                      else -> add to directory to ans 


        stack<string>st;
        int cnt = 0, n = path.size();
        for(int i = 0; i < n; ++i) {
            if(path[i] == '/') {
                if(i)
                    st.push(path.substr(i - cnt, cnt));

                while(i < n && path[i+1] == '/'){
                    ++i;
                }
                cnt = 0;
            }
            else
                ++cnt;
        }
        if(cnt)
            st.push(path.substr(n - cnt, cnt));
        
        vector<string> vec;
        int toBePopped = 0;
        while(!st.empty()) {
            string t = st.top();
            st.pop();

            if(t == ".." ){
                ++toBePopped;
            }
            else if (t == ".");
            else if(toBePopped == 0)
                vec.push_back(t);
            else
                --toBePopped;
        }
        
        n = vec.size();
        string ans = "";
        for(int i = n - 1; i >= 0; --i) {
            ans += "/" + vec[i];
        }
        
        return ans == ""? "/" : ans;
    }
};