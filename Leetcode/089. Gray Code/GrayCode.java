// Leetcode 89. Gray Code
// https://leetcode.com/problems/gray-code/description/
// Runtime: 1ms

// https://en.wikipedia.org/wiki/Gray_code

class Solution {
    public List<Integer> grayCode(int n) {
        LinkedList<Integer> res = new LinkedList<>();
        res.add(0);

        if (n == 0) {
            return res;
        }

        if (n == 1) {
            res.add(1);
            return res;
        }

        for (int i = 1; i < (int)Math.pow(2, n); i++) {
            res.add(i ^ i >> 1);
        }

        return res;
    }
}
