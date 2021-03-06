// Leetcode 15. 3Sum
// https://leetcode.com/problems/3sum/description/
// Runtime: 103ms

// 维基介绍，基本跟自己的想法吻合(排序和两边开始加)，但最后还是欠了火候没能写出n二次方的解法。。
// https://en.wikipedia.org/wiki/3SUM
// 以下代码为参考维基写的代码（维基的代码是不包括去重，需要自己加上）
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List< List<Integer> > res = new ArrayList<>();

        int[] sorted = nums;
        Arrays.sort(sorted);

        int last_a = Integer.MAX_VALUE;
        int last_b = Integer.MAX_VALUE;;
        int last_c = Integer.MAX_VALUE;;

        for (int i = 0; i < sorted.length - 2; i++) {
            int a = sorted[i];
            if (a == last_a) {
                continue;
            }
            int start = i + 1;
            int end = sorted.length - 1;
            
            last_b = Integer.MAX_VALUE;
            last_c = Integer.MAX_VALUE;
            while (start < end) {
                int b = sorted[start];
                if (b == last_b) {
                    start = start + 1;
                    continue;
                }

                int c = sorted[end];
                if (c == last_c) {
                    end = end - 1;
                    continue;
                }

                if (a + b + c == 0) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(a);
                    tmp.add(b);
                    tmp.add(c);
                    res.add(tmp);

                    last_a = a;
                    last_b = b;
                    last_c = c;
                    end = end - 1;
                } else if (a + b + c > 0) {
                    end = end - 1;
                } else {
                    start = start + 1;
                }
            }
        }
        return res;
    }
}
