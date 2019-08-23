// Leetecode 796. Rotate String
// https://leetcode.com/problems/rotate-string/
// Runtime: 0ms

func rotateString(A string, B string) bool {
    if len(A) != len (B) {
        return false
    }
    
    tmpStr := A + A
    var index int = strings.Index(tmpStr, B)
    if index == -1 {
        return false
    } else {
        return true
    }
}
