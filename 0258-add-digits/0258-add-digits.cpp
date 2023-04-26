class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return num;
        if(num % 9 == 0)
            return 9;
        return num % 9;
        // compact formula:
        // return num == 0 ? 0 : 1 + (num - 1) % 9;
        
    }
};