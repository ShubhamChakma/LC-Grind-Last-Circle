class Solution {
public:
    bool isPalindrome(int x) {

        int original = x;
        int rev = 0;

        while (x>0){
            int ld = x % 10;
            if (rev > INT_MAX/10 || rev < INT_MIN/10)
                return false;
            rev = (rev * 10) + ld;
            x = x/10;
        }   
        if (original == rev)
            return true;
        else 
            return false; 
    }   

};