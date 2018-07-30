// Leetcode 47. Permutations II
// https://leetcode.com/problems/permutations-ii/description/
// Runtime: 85ms (sucks..)

// 相比46题仅仅最后加了contain判断。显然这里极大地影响了性能
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
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
                    
                    // 罪魁祸首
                    if (!res.contains(ll)) {
                        res.add(ll);
                    }
                }
            }
            tmp.clear();
        }
        return res;
    }
}
