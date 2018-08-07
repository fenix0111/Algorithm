// Leetcode 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/
// Runtime: 4ms

// 用了深度搜索
class Solution {
    
    // 此函数负责着色
    void islandsDFS(boolean[][] vis, char[][] grid, int gridrow, int gridcol) {
        char LAND = '1';
        char SEA = '0';

        int row = grid.length;
        int col = grid[0].length;

        if (gridrow < 0 || gridrow >= row || gridcol < 0 || gridcol >= col) {
            return;
        }

        // if already visited
        if (vis[gridrow][gridcol]) {
            return;
        }

        // left,
        // up,
        // right,
        // bottom
        if (grid[gridrow][gridcol] == LAND) {
            vis[gridrow][gridcol] = true;
            islandsDFS(vis, grid, gridrow, gridcol - 1);
            islandsDFS(vis, grid, gridrow - 1, gridcol);
            islandsDFS(vis, grid, gridrow, gridcol + 1);
            islandsDFS(vis, grid, gridrow + 1, gridcol);
        } else {
            vis[gridrow][gridcol] = true;
            return;
        }
    }

    public int numIslands(char[][] grid) {
        if (grid.length == 0) {
            return 0;
        }

        int num = 0;

        int row = grid.length;
        int col = grid[0].length;
        char LAND = '1';
        char SEA = '0';

        boolean[][] visited = new boolean[row][col];

        // initialize visited
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                visited[r][c] = false;
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (visited[r][c] == false && grid[r][c] == LAND) {
                    num++;
                    islandsDFS(visited, grid, r, c);
                }
            }
        }

        return num;
    }
}
