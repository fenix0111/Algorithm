// Leetcode 704. Binary Search
// https://leetcode.com/problems/binary-search/
// Runtime: 4ms

// the first solution written by Rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut beg : usize = 0;
        let mut end : usize = nums.len() - 1;
        let mut mid : usize = (end - beg) / 2;
        
        while beg <= end {
            if target < nums[mid] {
                end = (mid - 1);
                if (end as i32) < 0 {
                    return -1;
                }
            } else if target > nums[mid] {
                beg = mid + 1;
            } else {
                return mid as i32;
            }
            
            mid = beg + (end - beg) / 2;
        }
        
        return -1;
    }
}
