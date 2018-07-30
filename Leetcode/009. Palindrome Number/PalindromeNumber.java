// Leetcode 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/description/
// Runtime: 259ms 

public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int dup = x;
        int pos = 0;
        while (dup != 0) {
            dup = dup / 10;
            pos++;
        }

        dup = x;
        int i = 0;
        while (i < (pos / 2 + 1)) {
            int a = x;
            dup = x;

            dup = dup / (int)Math.pow(10, i);
            a = dup % 10;

            int b = x;
            dup = x;
            dup = (int)(dup / Math.pow(10, pos - i - 1));
            b = dup % 10;

            if (a != b) {
                return false;
            }
            i++;
        }
        return true;
    }
    
    // 133ms 解法
    public boolean isPalindrome(int x) {
        long reverse = 0;
        long remainder = 0;
        
        // Verify provided integer is valid integer
        if(x >= Integer.MAX_VALUE || x <= Integer.MIN_VALUE)
            return false;
            
        // Check if integer provided is a single digit
        if(x >= 0 && x < 10)
            return true;
            
        long y = x;
        
        // Check if integer reversed equals integer provided
        while(y > 0)
        {
            reverse *= 10;
            remainder = y % 10;
            reverse += remainder;
            y /= 10;
        }
        
        if(x == (int)reverse)
            return true;
        return false;
    }
}
