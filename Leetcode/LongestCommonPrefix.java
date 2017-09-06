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
    
    // 8ms参考解法
    public String longestCommonPrefix_fast(String[] strs) {
        if(strs == null || strs.length == 0) 
        return "";
        
        String prefix = strs[0];
        
        for(int i = 1; i < strs.length; i++) {
            while(strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
            }
            if(prefix.equals(""))
                break;
        }
        
        return prefix;
    }
}
