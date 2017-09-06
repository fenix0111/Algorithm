// Leetcode 136. Single Number
// https://leetcode.com/problems/single-number/description/
// Runtime: 23ms

public class Solution {
    public int singleNumber(int[] nums) {
        int ret = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int v = map.get(nums[i]);
                v++;
                map.put(nums[i], v);
            } else {
                map.put(nums[i], 1);
            }
        }

        for (int j = 0; j < nums.length; j++) {
            int v = map.get(nums[j]);
            if (v == 1)
                ret = nums[j];
        }

        return ret;
    }
    
    // 1ms参考解法。位运算的巧妙运用
    public int singleNumber_fast(int[] nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
}
