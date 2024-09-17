class Solution {
public:
    bool isPalindrome(int x) {

        int digit;
        unsigned int ans = 0;
        int m = x;
        while( m > 0){
            digit = m % 10;
            ans = (ans * 10) + digit;
            m = m / 10;
        }
        if(ans == x){
            return true;
        }
        else{
            return false;
        }
    }
};