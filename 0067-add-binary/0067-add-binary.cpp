class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        bool cin = 0;
        string sum = "";
        if(n > m)
            swap(a, b), swap(n, m);
        //full adder eq
        int i = n - 1, j = m - 1;
        while(i >= 0){
            bool x = a[i] == '1', y = b[j] == '1';

            sum = to_string((x^y)^cin) + sum;
            cin = (x&y) | (cin&(x^y)); 

            --i, --j;
        }
        //half adder eq
        while(j >= 0){
            bool y = b[j] - '0';
            sum = to_string(y^cin) + sum;
            cin = y&cin; 
            --j;
        }
        if(cin)
            sum = "1" + sum;

        return sum;
        
    }
};