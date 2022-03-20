# Leetcode 1184. Distance Between Bus Stops
# https://leetcode.com/problems/distance-between-bus-stops/

# @param {Integer[]} distance
# @param {Integer} start
# @param {Integer} destination
# @return {Integer}

# using prefix sum
def distance_between_bus_stops(distance, start, destination)
    sz = distance.length
    
    total_dist = distance.sum
    prefix_sum = Array.new(sz + 1, 0)

    i = 0
    while i < sz
        prefix_sum[i + 1] = prefix_sum[i] + distance[i]
        i += 1
    end
    
    from = 0
    to = 0
    if start < destination
        from = start
        to = destination
    else
        from = destination
        to = start
    end
    
    clockwise_dist = prefix_sum[to] - prefix_sum[from]
    counter_clockwise_dist = total_dist - clockwise_dist
    
    if clockwise_dist < counter_clockwise_dist
        return clockwise_dist
    else
        return counter_clockwise_dist
    end
end
