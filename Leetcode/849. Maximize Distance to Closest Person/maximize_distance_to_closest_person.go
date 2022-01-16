// scan from left to right then right to left
// record the distance to people
// finally select the maximum value from shorter distances

func max(x, y int) int {
    if x < y {
        return y
    } else {
        return x
    }
}

func maxDistToClosest(seats []int) int {
    var sz = len(seats)
    var ltor = make([]int, sz, sz)
    var rtol = make([]int, sz, sz)
    
    var last int = -1
    for i := 0; i < sz; i++ {
        if seats[i] == 1 {
            last = i
        } else {
            if last != -1 {
                ltor[i] = i - last
            } else {
                ltor[i] = math.MaxInt32
            }
        }
    }
    
    last = -1
    for i := sz - 1; i >= 0; i-- {
        if seats[i] == 1 {
            last = i
        } else {
            if last != -1 {
                rtol[i] = last - i
            } else {
                rtol[i] = math.MaxInt32
            }
        }
    }
    
    var result = math.MinInt32
    for i := 0; i < sz; i++ {
        if ltor[i] > rtol[i] {
            result = max(result, rtol[i])
        } else {
            result = max(result, ltor[i])
        }
    }
    
    return result
}
