// Leetcode 892. Surface Area of 3D Shapes
// https://leetcode.com/problems/surface-area-of-3d-shapes/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let result = 0;
    let n = grid.length;
    
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] == 0) {
                continue;
            }
            
            result += 2;
            
            if (r == 0) {
                if (c == 0 || c == n - 1) {
                    result += (2 * grid[r][c]);
                } else {
                    result += grid[r][c];
                }
            }
            
            if (r == n - 1) {
                if (c == 0 || c == n - 1) {
                    result += (2 * grid[r][c]);
                } else {
                    result += grid[r][c];
                }
            }
            
            if (r > 0 && r < n - 1 && (c == 0 || c == n - 1)) {
                result += grid[r][c];
            }
            
            if (r > 0 && grid[r][c] > grid[r - 1][c]) {
                result += (grid[r][c] - grid[r - 1][c]);
            }
            
            if (r < n - 1 && grid[r][c] > grid[r + 1][c]) {
                result += (grid[r][c] - grid[r + 1][c]);
            }
            
            if (c < n - 1 && grid[r][c] > grid[r][c + 1]) {
                result += (grid[r][c] - grid[r][c + 1]);
            }
            
            if (c > 0 && grid[r][c] > grid[r][c - 1]) {
                result += (grid[r][c] - grid[r][c - 1]);
            }
        }
    }
    
    return result;
};
