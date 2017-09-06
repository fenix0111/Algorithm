// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/description/
// Runtime: 2ms

// 使用临时数组存放被挤出去的部分，然后把目标数组往后移k位，最后把临时数组的数据复制到原数组里
class Solution {
    public void rotate(int[] nums, int k) {
        if (k == 0) {
            return;
        }

        // 注意循环
        int numOfMove = k % nums.length;

        int[] tmp = new int[numOfMove];

        for (int i = 0; i < tmp.length; i++) {
            tmp[i] = nums[nums.length - numOfMove + i];
        }
        for (int i = nums.length - numOfMove - 1; i >= 0; i--) {
            nums[i + numOfMove] = nums[i];
        }
        for (int i = 0; i < tmp.length; i++) {
            nums[i] = tmp[i];
        }
    }
    
    // 网上快速解法：
    public void rotate(int[] nums, int k) {
        int[] rotatedArray = new int[nums.length];
        int cut = nums.length - (k % nums.length);
        int count = 0;
        for (int i=cut; i < nums.length; i++) {
            rotatedArray[count] = nums[i];
            count++;
        }
        for (int j=0; j < cut; j++) {
            rotatedArray[count] = nums[j];
            count++;
        }
        System.arraycopy(rotatedArray,0,nums,0,nums.length);
    }
}
