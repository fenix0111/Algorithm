// Leetcode 78. Subsets
// https://leetcode.com/problems/subsets/description/
// Runtime: 4ms

// 递归轮着往list里加数
class Solution {
    void subsetRecr(int[] nums, int idx, LinkedList<Integer> list, List<List<Integer>> res) {
        for (int j = idx + 1; j < nums.length; j++) {
            // 这部分应该可以再优化
            LinkedList ll = new LinkedList();
            ll.addAll(list);
            ll.add(nums[j]);
            res.add(ll);
            subsetRecr(nums, j, ll, res);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();

        // 先加一个empty set
        List<Integer> empty = new LinkedList<>();
        res.add(empty);

        if (nums.length == 0)
            return res;

        for (int i = 0; i < nums.length; i++) {
            LinkedList<Integer> ll = new LinkedList<>();
            ll.add(nums[i]);
            res.add(ll);
            subsetRecr(nums, i, ll, res);
        }
        return res;
    }
}
