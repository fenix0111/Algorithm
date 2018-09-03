// Leetcode 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/description/
// Runtime: 9ms

// using map to chech wheter char in string s have many mapping in string t.
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() == 0) {
            return true;
        }
        
        char cs, ct;
        HashMap<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            cs = s.charAt(i);
            ct = t.charAt(i);
            if (!map.containsKey(cs)) {
                if (map.containsValue(ct)) {
                    return false;
                }
                map.put(cs, ct);
            } else {
                Character tt = map.get(cs);
                if (tt != ct) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
