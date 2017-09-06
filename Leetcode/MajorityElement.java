// Leetcode 169. Majority Element
// https://leetcode.com/problems/majority-element/description/
// Runtime: 6ms

class Solution {
    public int majorityElement(int[] nums) {
        int line = nums.length / 2;
        int res = 0;

        int []tmp = nums;
        Arrays.sort(tmp);
        
        int times = 1;
        int max = 0;
        for (int i = 0; i < tmp.length; i++) {
            if (i != 0) {
                if (tmp[i] == tmp[i - 1]) {
                    times++;
                    if (times > max) {
                        max = times;
                        if (max >= line) {
                            res = tmp[i];
                        }
                    }
                } else {
                    times = 1;
                }
            } else {
                res = tmp[i];
            }
        }
        return res;
    }
    
    // 2ms参考解法
    public int majorityElement_fast(int[] num) {
        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++) {
            if (count==0) {
                count++;
                major=num[i];
            } else if (major == num[i]) {
                count++;
            } else if (major != num[i]) {
                count--;
            }
        }
        return major;
    }
}
