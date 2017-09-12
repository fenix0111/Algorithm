// Leetcode 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/description/
// Runtime: 78ms (不及格)

// 跟Combination Sum类似。仅不允许重复使用数组元素。
public class Solution {
    void csRecur(int[] nums, int index, int target, List<Integer> list, List<List<Integer>> res) {
        if (target == 0) {
            Collections.sort(list);
            if (!res.contains(list)) {
                res.add(list);
            }
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < nums.length; i++) {
            int n = nums[i];
            List<Integer> l = new LinkedList<>();
            l.addAll(list);
            l.add(n);
            csRecur(nums, i + 1,target - n, l, res);
        }
    }

    public List< List<Integer> > combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<>();
        int len = candidates.length;

        for (int i = 0; i < len; i++) {
            int n = candidates[i];
            List<Integer> l = new LinkedList<>();
            l.add(n);
            csRecur(candidates, i + 1,target - n, l, res);
        }
        return res;
    }
}
