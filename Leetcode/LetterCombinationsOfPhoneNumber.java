// Leetcode 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Runtime: 4ms

// 程序不美..
class Solution {
    void letterRecur(List<String> list, List<String> ss, int idx, StringBuilder sb) {
        if (idx == ss.size() - 1) {
            for (int i = 0; i < ss.get(idx).length(); i++) {
                sb.append(ss.get(idx).charAt(i));
                list.add(sb.toString());
                sb.setLength(sb.toString().length() - 1);
            }
        } else {
            for (int i = 0; i < ss.get(idx).length(); i++) {
                StringBuilder tmp = new StringBuilder();
                if (sb != null) {
                    tmp = sb;
                }
                tmp.append(ss.get(idx).charAt(i));
                letterRecur(list, ss, idx + 1, tmp);
                tmp.setLength(tmp.toString().length() - 1);
            }
        }
    }
    
    public List<String> letterCombinations(String digits) {
        List<String> res = new LinkedList<>();
        if (digits.length() == 0) {
            return res;
        }
        String[] table = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> ss = new LinkedList<>();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < digits.length(); i++) {
            ss.add(table[digits.charAt(i) - 48]); // '0'的ASCII码为48
        }

        letterRecur(res, ss, 0, sb);

        return res;
    }
}
