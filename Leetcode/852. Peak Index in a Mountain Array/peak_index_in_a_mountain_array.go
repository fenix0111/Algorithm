// Leetcode 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

func peakIndexInMountainArray(arr []int) int {
    var peak int = 0
    
    for i := 1; i < len(arr) - 1; i++ {
        if arr[i] > arr[i - 1] && arr[i] > arr[i + 1] {
            peak = i
            break
        }
    }
    
    return peak
}
