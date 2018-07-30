// Leetcode 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/
// Runtime: 13ms

public class Solution {
    public boolean isPalindrome(String s) {
        int first = 0;
        int last = s.length() - 1;

        Character f;
        Character l;
        while (first <= last) {
            f = s.charAt(first);
            l = s.charAt(last);
            if (!(Character.isDigit(f) || Character.isAlphabetic(f))) {
                first++;
                continue;
            }

            if (!(Character.isDigit(l) || Character.isAlphabetic(l))) {
                last--;
                continue;
            }

            if (Character.toLowerCase(f) != Character.toLowerCase(l)) {
                return false;
            }
            first++;
            last--;
        }

        return true;
    }
    
    // 2ms参考解法
    public boolean isPalindrome_fast(String s) {
        if(s.equals(""))
    	    return true;
        int length = s.length();
        int j = 0;
        int k = length-1;
        while(j < k) {
            int a = s.charAt(j);
            int b = s.charAt(k);
            if((a < 65 || a > 90) && (a < 97 || a > 122) && (a < 48 || a > 57)) {
                j++;
                continue;
            }
            if((b < 65 || b > 90) && (b < 97 || b > 122) && (b < 48 || b > 57)) {
                k--;
                continue;
            }
            if(a != b){
                if(a >= 65 && a <= 90){
            	    return (a - 'A') == (b - 'a');
                }
                if(a >= 97 && a <= 122){
            	    return (a - 'a') == (b - 'A');
                }
                return false;
            }
            j++;
            k--;
        }
        return true;
    }
}
