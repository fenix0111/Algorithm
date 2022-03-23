# Leetcode 1266. Minimum Time Visiting All Points
# https://leetcode.com/problems/minimum-time-visiting-all-points/

# @param {Integer[][]} points
# @return {Integer}
def get_max(x, y)
    if x < y
        return y
    else
        return x
    end
end

def min_time_to_visit_all_points(points)
    min_time = 0
    points.each_cons(2) do |p|
        x = p[0]
        y = p[1]
        
        min_time += get_max((x[0] - y[0]).abs, (x[1] - y[1]).abs)        
    end
    
    return min_time
end
