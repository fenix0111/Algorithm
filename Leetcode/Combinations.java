// Leetcode 77. Combinations
// https://leetcode.com/problems/combinations/description/
// Runtime: 145ms (horrible..)

// 把78题做了点修改。。但很慢, 需要活用k值改进改进
class Solution {
    void combineRecr(int[] nums, int idx, LinkedList<Integer> list, List<List<Integer>> res, int k) {
        for (int j = idx + 1; j < nums.length; j++) {
            LinkedList ll = new LinkedList();
            ll.addAll(list);
            ll.add(nums[j]);
            if (ll.size() == k) {
                res.add(ll);
            }
            combineRecr(nums, j, ll, res, k);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new LinkedList<>();

        int[] nums = new int[n];
        for (int i = 1; i <= n; i++) {
            nums[i - 1] = i;
        }

        for (int i = 0; i < nums.length; i++) {
            LinkedList<Integer> ll = new LinkedList<>();
            ll.add(nums[i]);
            if (ll.size() == k) {
                res.add(ll);
            }
            combineRecr(nums, i, ll, res, k);
        }

        return res;
    }
}
