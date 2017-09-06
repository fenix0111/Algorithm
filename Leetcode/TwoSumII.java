// Leetcode 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
// Runtime: 1ms

// 主要思路是常用的“两边指针朝对象移动”。因为有“已排序”的前提，所以大于target就end往左移（让和变小）小于就begin往右移（让和变大）。
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {0, 0};

        int begin = 0;
        int end = numbers.length - 1;
        while (begin <= end) {
            if (numbers[begin] + numbers[end] == target) {
                res[0] = begin + 1;
                res[1] = end + 1;
                break;
            } else if (numbers[begin] + numbers[end] > target) {
                end = end - 1;
            } else if (numbers[begin] + numbers[end] < target) {
                begin = begin + 1;
            }
        }
        return res;
    }
}
