# Leetcode 1030. Matrix Cells in Distance Order
# https://leetcode.com/problems/matrix-cells-in-distance-order/

# @param {Integer} rows
# @param {Integer} cols
# @param {Integer} r_center
# @param {Integer} c_center
# @return {Integer[][]}
def all_cells_dist_order(rows, cols, r_center, c_center)
    dist = Hash.new{ |hsh, key| hsh[key] = [] }
    
    (0...rows).each do |r|
        (0...cols).each do |c|
            dx = (c - c_center).abs
            dy = (r - r_center).abs
            dist[dx + dy] << [r, c]
        end
    end
    
    result = []
    dist = dist.sort
    dist.each do |k, v|
        v.each do |p|
            result << p
        end
    end
    
    return result
end
