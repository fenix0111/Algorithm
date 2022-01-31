// Leetcode 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/
// time complexity: O(R*C)
// space complexity: O(1)

func maximumWealth(accounts [][]int) int {
    var row = len(accounts)
    var col = len(accounts[0])
    
    var result = 0
    
    for r := 0; r < row; r++ {
        var sum = 0
        for c := 0; c < col; c++ {
            sum += accounts[r][c]
        }
        
        if sum > result {
            result = sum
        }
    }
    
    return result;
}
