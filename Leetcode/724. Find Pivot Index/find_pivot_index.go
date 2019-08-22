// Leetcode 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// Runtime: 20ms

func pivotIndex(nums []int) int {
    size := len(nums)
    if size < 3 {
        return -1
    }
    
    beg := 0
    sum := 0
    for _, n := range nums {
        sum += n
    }
    
    left := 0
    right := sum
    for beg < size {
        right -= nums[beg]
        if left == right {
            return beg
        } else {
            left += nums[beg]
        }
        beg++
    }
    
    return -1
}
