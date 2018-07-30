// Leetcode 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/
// Runtime: 4ms

// 用了深度搜索
class Solution {
    boolean islandsDFS(boolean[][] vis, char[][] grid, int gridrow, int gridcol) {
        char LAND = '1';
        char SEA = '0';

        int row = grid.length;
        int col = grid[0].length;

        if (gridrow < 0 || gridrow >= row || gridcol < 0 || gridcol >= col) {
            return false;
        }

        // if already visited
        if (vis[gridrow][gridcol]) {
            return false;
        }

        // left,
        // up,
        // right,
        // bottom
        if (grid[gridrow][gridcol] == LAND) {
            vis[gridrow][gridcol] = true;
            
            // 直接return每个遍历的话有可能因为中间某一个遍历返回true从而直接返回导致得出错误的结果
            boolean left = islandsDFS(vis, grid, gridrow, gridcol - 1);
            boolean up = islandsDFS(vis, grid, gridrow - 1, gridcol);
            boolean right = islandsDFS(vis, grid, gridrow, gridcol + 1);
            boolean bottom = islandsDFS(vis, grid, gridrow + 1, gridcol);
            return left || up || right || bottom || true;

        } else {
            vis[gridrow][gridcol] = true;
            return false;
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
                if (islandsDFS(visited, grid, r, c)) {
                    num++;
                }
            }
        }
        return num;
    }
}
