// Leetcode 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/
// Runtime: 13ms

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len = strs.length;
        if (len == 0)
            return "";
        if (len == 1)
            return strs[0];
        
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < len; i++)
        {
            int tmplen = strs[i].length();
            if (tmplen < shortest)
                shortest = tmplen;
        }
        if (shortest == 0)
            return "";
        String prefix = "";
        
        for (int i = 0; i < shortest; i++)
        {
            String tmp = strs[0].substring(0, i + 1);
            for (int j = 0; j < len; j++)
            {
                if (!strs[j].substring(0, i + 1).equals(tmp))
                    return prefix;
            }
            prefix = tmp;
        }
        return prefix;
    }
}
