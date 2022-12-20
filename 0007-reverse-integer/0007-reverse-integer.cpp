class Solution {
public:
    int reverse(int x) {
        int n = x, ans = 0;
        if(n == INT_MIN) return 0;
        
        int sign = x < 0 ? 1 : 0;
        
        
        if(sign) n *= -1;
        while(n){
            int dig = n%10;
             //checking overflow
            if(ans> INT_MAX/10 || ans > INT_MAX/10+dig)
                return 0;
            ans = ans*10 + dig;
            n/= 10;
        }
        
       
        
       
        return sign? -1*ans : ans;
    }
};