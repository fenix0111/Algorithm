// Leetcode 806. Number of Lines To Write String
// https://leetcode.com/problems/number-of-lines-to-write-string/
// time complexity: O(len(s))
// space complexity: O(1)

func numberOfLines(widths []int, s string) []int {
    var result = make([]int, 2)
    
    var lines int = 1
    var w int = 0
    for _, c := range s {
        if w + widths[c - 'a'] > 100 {
            w = 0
            lines++
        }
        
        w += widths[c - 'a']
    }
    
    result[0] = lines
    result[1] = w
    
    return result
}
