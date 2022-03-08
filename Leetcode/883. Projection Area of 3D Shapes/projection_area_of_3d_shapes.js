// Leetcode 883. Projection Area of 3D Shapes
// https://leetcode.com/problems/projection-area-of-3d-shapes/

// funny problem with horrible description

/**
 * @param {number[][]} grid
 * @return {number}
 */
var projectionArea = function(grid) {
    let xz = 0;
    let xy = 0;
    let yz = 0;
    let n = grid.length;
    let maxRow = Array(n).fill(0);
    let maxCol = Array(n).fill(0);
    
    // xy
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] != 0) {
                xy += 1;
                maxCol[c] = Math.max(maxCol[c], grid[r][c]);
                maxRow[r] = Math.max(maxRow[r], grid[r][c]);
            }
        }
    }
    
    // yz
    maxRow.forEach((val) => yz += val);
    
    // xz
    maxCol.forEach((val) => xz += val);

    return xy + xz + yz;
};
