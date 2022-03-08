// Leetcode 896. Monotonic Array
// https://leetcode.com/problems/monotonic-array/
// time complexity: O(N)
// space complexity: O(1)

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function(nums) {
    let inc = false;
    let dec = false;
    
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            dec = true;
        } else if (nums[i] < nums[i + 1]) {
            inc = true;
        }
    }
    
    return inc == false || dec == false;
};
