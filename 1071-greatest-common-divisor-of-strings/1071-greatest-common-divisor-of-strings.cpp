class Solution {
public:
    
    string gcdOfStrings(string str1, string str2) {
        //get x which divides str1
        
        if(str1.size() > str2.size())
            swap(str1, str2);

        int n = str1.size(), m = str2.size();
        bool flag = 0;
        for(int k = str1.size(); k>=1; --k){
            if(n % k != 0 || m % k !=0)
                continue;
            string sub = str1.substr(0, k);
            for(int i=k; i<n; i+=k){
                if(str1.substr(i, k) != sub){
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;

            for(int i=0; i<m; i+=k){
                if(str2.substr(i, k) != sub){
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            
            return sub;
        }
        
        return "";
    }
};