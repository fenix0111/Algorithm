// Leetcode 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/description/
// Runtime: 7ms

public class Solution {
    public int lengthOfLastWord(String s) {
        String[] splitted = s.split(" ");
        if (splitted.length == 0) {
            return 0;
        }
        String last = splitted[splitted.length - 1];
        return last.length();
    }
    
    // 4ms参考解法
    public int lengthOfLastWord(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int i = s.length() - 1;
        while (i >= 0) {
            if (s.charAt(i) == ' ') {
                i--;
            } else {
                break;
            }
        }
        if (i < 0) {
            return 0;
        }
        int endingIndex = i;
        int startingIndex = i;
        while (i >= 0) {
            if (s.charAt(i) != ' ') {
                startingIndex = i;
                i--;
            } else {
                break;
            }
        }
        return endingIndex - startingIndex + 1;
    }
}
