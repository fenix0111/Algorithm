// Leetcode 39. Combination Sum
// https://leetcode.com/problems/combination-sum/description/
// Runtime: 77ms (不及格, 仅仅比2.5%的用户快)

// 使用了回溯算法
class Solution {
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
            int c = target / n;

            if (c == 0) {
                List<Integer> l = new LinkedList<>();
                l.addAll(list);
                l.add(n);
                csRecur(nums, index + 1,target - n, l, res);
            }
            while (c > 0) {
                int cr = c;
                List<Integer> l = new LinkedList<>();
                l.addAll(list);
                while (cr > 0) {
                    l.add(n);
                    cr--;
                }
                csRecur(nums, index + 1,target - (n * c), l, res);
                c--;
            }
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new LinkedList<>();
        int len = candidates.length;

        for (int i = 0; i < len; i++) {
            int n = candidates[i];
            int c = target / n;

            while (c > 0) {
                int cr = c;
                List<Integer> l = new LinkedList<>();
                while (cr > 0) {
                    l.add(n);
                    cr--;
                }
                csRecur(candidates, i + 1,target - (n * c), l, res);
                c--;
            }
        }

        return res;
    }
}
