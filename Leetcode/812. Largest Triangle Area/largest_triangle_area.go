// Leetcode 812. Largest Triangle Area
// https://leetcode.com/problems/largest-triangle-area/

// https://cp-algorithms.com/geometry/oriented-triangle-area.html
func largestTriangleArea(points [][]int) float64 {
    var result float64 = math.SmallestNonzeroFloat64
    
    for i := 0; i < len(points); i++ {
        for j := 0; j < len(points); j++ {
            if i == j {
                continue
            }
            for k := 0; k < len(points); k++ {
                if j == k {
                    continue
                }
                
                pi := points[i]
                pj := points[j]
                pk := points[k]
                
                area := (float64(pj[0]) - float64(pi[0])) * (float64(pk[1]) - float64(pj[1])) - (float64(pk[0]) - float64(pj[0])) * (float64(pj[1]) - float64(pi[1]))
                
                area = 0.5 * area
                
                if area > result {
                    result = area
                }
            }
        }
    }
    
    return result
}
