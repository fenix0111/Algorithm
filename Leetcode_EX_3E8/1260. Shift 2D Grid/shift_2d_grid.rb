# Leetcode 1260. Shift 2D Grid
# https://leetcode.com/problems/shift-2d-grid/

# @param {Integer[][]} grid
# @param {Integer} k
# @return {Integer[][]}
def shift_grid(grid, k)
    rows = grid.length
    cols = grid[0].length
    
    k = k % (rows * cols)
    
    newR = k / cols
    newC = k % cols
    
    newGrid = Array.new(rows) { Array.new(cols, 0) }
    r = 0
    c = 0
    
    # copy from original grid to new grid, from [newR, newC] to the end of the grid 
    while newR < rows
        while newC < cols
            newGrid[newR][newC] = grid[r][c]
            c += 1
            newC += 1
            if c == cols
                c = 0
                r += 1
            end
        end
        
        newR += 1
        newC = 0
    end
    
    newR = 0
    newC = 0
    
    # fill the new grid with remaining elements
    while r < rows
        while c < cols
            newGrid[newR][newC] = grid[r][c]
            c += 1
            newC += 1
            if newC == cols
                newC = 0
                newR += 1
            end
        end
        
        r += 1
        c = 0
    end
    
    return newGrid
    
end
