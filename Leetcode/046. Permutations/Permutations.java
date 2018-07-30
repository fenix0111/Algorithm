// Leetecode 46. Permutations
// https://leetcode.com/problems/permutations/description/
// Runtime: 8ms

// 实在想不出如何用递归写
// 转而采用了插入的方法。
// 例如, 先写个"x", 左右加"y"成为"xy", "yx", 接着加"z"如此加到最后一个字符
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List< List<Integer> > res = new LinkedList<>();
        int len = nums.length;
        if (len == 1) {
            List<Integer> l = new LinkedList<>();
            l.add(nums[0]);
            res.add(l);
            return res;
        }

        LinkedList< List<Integer> > tmp = new LinkedList<>();
        for (int p = 0; p < nums.length - 1; p++) {
            if (res.isEmpty()) {
                // first time
                LinkedList<Integer> fl = new LinkedList<>();
                fl.add(nums[p]);
                res.add(fl);
            }

            if (!res.isEmpty()) {
                tmp.addAll(res);
                res.clear();
            }

            for (int s = 0; s < tmp.size(); s++) {
                LinkedList<Integer> inner = new LinkedList<>();
                inner.addAll(tmp.get(s));
                int num = nums[p + 1];

                for (int i = 0; i <= inner.size(); i++) {
                    LinkedList<Integer> ll = new LinkedList<>();
                    ll.addAll(inner);
                    ll.add(i, num);
                    res.add(ll);
                }
            }
            tmp.clear();
        }
        return res;
    }
}
