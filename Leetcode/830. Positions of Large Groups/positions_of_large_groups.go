// Leetcode 830. Positions of Large Groups
// https://leetcode.com/problems/positions-of-large-groups/

func largeGroupPositions(s string) [][]int {
    var result [][]int
    var lastC rune = 0
    var index int = 0;
    for i, c := range s {
        if lastC == 0 {
            lastC = c
            index = i
            continue
        }
        
        if lastC != c {
            if i - index >= 3 {
                result = append(result, []int{index, i - 1})
            }
            
            lastC = c
            index = i
        }
    }
    
    if len(s) - index >= 3 {
        result = append(result, []int{index, len(s) - 1})
    }
    
    return result
}
