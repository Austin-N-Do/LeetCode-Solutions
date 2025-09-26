class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 || x % 10 == 0 && x != 0){
            return false;
        }

        int reversed = 0;

        while (reversed < x) {
        // get the last digit
        int lastDigit = x % 10;
        // add it to the reversed number
        reversed = reversed * 10 + lastDigit; 
        // remove the last digit from x 
        x = x / 10;                  
}
        if ( x == reversed || x == reversed/10){
            return true;
        }
        else {
            return false;
        }
    }
};