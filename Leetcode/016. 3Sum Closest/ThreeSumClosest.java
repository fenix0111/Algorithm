// Leetcode 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/
// Runtime: 24ms

// 3Sum题的一个变种。
// 给一个数组和目标值，要求返回最接近目标值的三个数之和。
// 因为没有唯一性判断等问题，把3Sum的代码稍作修改即可。

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int sum = 0;
        int diff = Integer.MAX_VALUE;

        int[] sorted = nums;
        Arrays.sort(sorted);

        for (int i = 0; i < sorted.length - 2; i++) {
            int a = sorted[i];

            int start = i + 1;
            int end = sorted.length - 1;

            while (start < end) {
                int b = sorted[start];
                int c = sorted[end];

                if (a + b + c == target) {
                    return target;
                } else if (a + b + c > target) {
                    if (Math.abs(target - a - b - c) < diff) {
                        diff = Math.abs(target - a - b - c);
                        sum = a + b + c;
                    }
                    end = end - 1;
                } else {
                    start = start + 1;
                    if (Math.abs(target - a - b - c) < diff) {
                        diff = Math.abs(target - a - b - c);
                        sum = a + b + c;
                    }
                }
            }
        }
        return sum;
    }
}
