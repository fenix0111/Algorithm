// Leetcode 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/submissions/1
// Runtime: 9ms

// use backtracking
class Solution {
    boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            if (s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    void pHelper(String s, int begin, ArrayList<String> list, List< List<String> > res) {
        int len = s.length();
        
        if (begin == len) {
            ArrayList ll = new ArrayList<>();
            ll.addAll(list);
            res.add(ll);
            return;
        }
        
        for (int i = begin + 1; i <= len; i++) {
            if (isPalindrome(s.substring(begin, i))) {
                list.add(s.substring(begin, i));
                pHelper(s, i, list, res);
                list.remove(list.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        List< List<String> > res = new ArrayList<>();
        if (null == s || s.length() == 0) {
            return res;
        }
        
        // extra space to save partitioned strings
        ArrayList<String> list = new ArrayList<>();
        
        pHelper(s, 0, list, res);
        
        return res;
    }
}
