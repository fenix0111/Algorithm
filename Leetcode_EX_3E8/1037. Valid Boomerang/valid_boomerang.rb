# Leetcode 1037. Valid Boomerang
# https://leetcode.com/problems/valid-boomerang/

# @param {Integer[][]} points
# @return {Boolean}
INF = 1000000000
EPS = 0.00000001
def is_boomerang(points)
    if points[1][0] == points[0][0] && points[1][1] == points[0][1]
        return false
    end
    
    if points[1][0] == points[2][0] && points[1][1] == points[2][1]
        return false
    end
    
    if points[2][0] == points[0][0] && points[2][1] == points[0][1]
        return false
    end
    
    d1 = 0
    d2 = 0
    if (points[1][0] - points[0][0]) != 0
        d1 = (points[1][1] - points[0][1]).to_f / (points[1][0] - points[0][0]).to_f 
    else
        if (points[1][1] - points[0][1]) == 0
            d1 = 0
        else
            d1 = INF
        end
    end
    
    if (points[2][0] - points[1][0]) != 0
        d2 = (points[2][1] - points[1][1]).to_f / (points[2][0] - points[1][0]).to_f 
    else
        if (points[2][1] - points[1][1]) == 0
            d2 = 0
        else
            d2 = INF
        end
    end
     
    return (d1 - d2).abs > EPS
end
