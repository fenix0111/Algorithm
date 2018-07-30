// Leetcode 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/
// Runtime: 11ms

// 用的是弱智迭代法。快速解法用的回溯算法。
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        Set<String> tmpset = new LinkedHashSet<>();

        List<String> last = new ArrayList<>();

        String one = "()";
        tmpset.add(one);
        StringBuilder sb;

        for (int i = 1; i < n; i++) {

            last.addAll(tmpset);

            tmpset.clear();
            for (int k = 0; k < last.size(); k++) {
                String stmp = last.get(k);
                sb = new StringBuilder(stmp);

                for (int j = 1; j <= sb.length(); j++) {
                    sb.insert(j, "()");
                    tmpset.add(sb.toString());
                    sb.setLength(stmp.length());
                    sb.replace(0, stmp.length(), stmp);
                }
            }
            last.clear();
        }

        res.addAll(tmpset);

        return res;
    }
    
    // 3ms参考解法
    public List<String> generateParenthesis_fast(int n) {
        List<String> rst = new ArrayList<String>();
        backtrack(rst, "", 0, 0, n);
        return rst;
    }
    
    private void backtrack(List<String> list, String str, int left, int right, int max) {
        if (str.length() == max * 2) {
            list.add(str);
            return;
        }
        if (left < max) 
            backtrack(list, str + "(", left + 1, right, max);
        if (right < left) 
            backtrack(list, str + ")", left, right + 1, max);
    }
}
