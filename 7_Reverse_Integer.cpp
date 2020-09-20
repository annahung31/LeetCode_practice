//Problem: https://leetcode.com/problems/reverse-integer/


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int pop, temp;
        while (x!=0){
            pop = x % 10;
            x = x/10;
            
            if (rev > INT_MAX/10 || rev == INT_MAX/10 && pop > 7){
                return 0;
            }
            if (rev < INT_MIN/10 || rev == INT_MIN/10 && pop < -8){
                return 0;
            }
            
            temp = rev * 10 + pop;
            rev = temp;
        }
        
        return rev;
        
    }
};
