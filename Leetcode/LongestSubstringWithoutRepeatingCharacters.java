// Leetcode 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Runtime: 142 ms (不及格, 大部分集中于40~60ms)

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return len;
        }

        int max = 0;
        int blen = 128;
        
        // Lookup table, 保存相应字符是否出现过, 原始类型总是自快的。
        // 一个boolean值只占1bit
        boolean[] lt = new boolean[blen];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length() - 1; i++) {
            char ci = s.charAt(i);
            sb.append(ci);
            lt[ci] = true;

            for (int j = i + 1; j < s.length(); j++) {
                char cj = s.charAt(j);
                if (lt[cj] == false) {
                    sb.append(cj);
                    lt[cj] = true;
                } else {
                    int innerLen = sb.toString().length();
                    if (innerLen > max) {
                        max = innerLen;
                    }

                    // 清空Stringbuilder和lookup table
                    sb.setLength(0);
                    for (int ii = 0; ii < blen; ii++) {
                        lt[ii] = false;
                    }
                    break;
                }
            }

            if (sb.toString().length() > max) {
                max = sb.toString().length();
            }

            sb.setLength(0);
            for (int ii = 0; ii < blen; ii++) {
                lt[ii] = false;
            }
        }

        return max;
    }
}
