class Solution {
public:
    int addDigits(int num) {
        while(num > 9) {
            int n = num, sum = 0;
            while(n) {
                int d = n % 10;
                sum += d;
                n /= 10;
            }
            num = sum;
        }
        return num;
    }
};