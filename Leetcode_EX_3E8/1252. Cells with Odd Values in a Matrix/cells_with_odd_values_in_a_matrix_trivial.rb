# Leetcode 1252. Cells with Odd Values in a Matrix
# https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
# time complexity: O(mn)
# space complexity: O(mn)

# @param {Integer} m
# @param {Integer} n
# @param {Integer[][]} indices
# @return {Integer}
def odd_cells(m, n, indices)
    mat = Array.new(m) { Array.new(n, 0) }
    
    indices.each do |index|
        r = index[0]
        c = index[1]
        
        for i in (0...m)
            mat[i][c] += 1
        end
        
        for i in (0...n)
            mat[r][i] += 1
        end
        
    end
    
    result = 0
    for r in (0...mat.size)
        for c in (0...mat[r].size)            
            if mat[r][c] % 2 == 1
                result += 1
            end
        end
    end
    
    return result
end
