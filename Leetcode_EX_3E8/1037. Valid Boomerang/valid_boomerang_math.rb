# @param {Integer[][]} points
# @return {Boolean}

# using math
def is_boomerang(points)
    return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) != 
    (points[0][0] - points[2][0]) * (points[0][1] - points[1][1])
end
