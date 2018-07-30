// Leetcode 79. Word Search
// https://leetcode.com/problems/word-search/description/
// Runtime: 41ms

// 用简单的四方向搜索+辅助的访问判定表的方法做的
// 感觉又像是图相关问题
class Solution {
    boolean srch(char[][] board, char[] word, int row, int col, int index, boolean[][] visited) {
        boolean res = false;
        int maxrow = board.length - 1;
        int maxcol = board[0].length - 1;

        if (index == word.length) 
            return true;

        if (col > maxcol) 
            return false;

        if (row < 0) 
            return false;

        if (row > maxrow) 
            return false;

        if (col < 0) 
            return false;

        if (visited[row][col])
            return false;

        visited[row][col] = true;
        if (board[row][col] == word[index]) {
            if  (   srch(board, word, row, col - 1, index + 1, visited) ||
                    srch(board, word, row, col + 1, index + 1, visited) ||
                    srch(board, word, row - 1, col, index + 1, visited) ||
                    srch(board, word, row + 1, col, index + 1, visited) ) {
                return true;
            } else {
                visited[row][col] = false;
            }
        } else {
            visited[row][col] = false;
            return false;
        }
        return false;
    }

    public boolean exist(char[][] board, String word) {
        char[] w = word.toCharArray();

        int maxrow = board.length - 1;
        int maxcol = board[0].length - 1;

        boolean[][] visited = new boolean[maxrow + 1][maxcol + 1];
        for (int i = 0; i <= maxrow; i++) {
            for (int j = 0; j <= maxcol; j++) {
                visited[i][j] = false;
            }
        }

        int r = 0;
        int c = 0;
        int index = 0;

        while (r <= maxrow && c <= maxcol) {
            if (board[r][c] != w[index]) {
                c++;
                // move to next row
                if (c > maxcol) {
                    c = 0;
                    r++;
                }
            } else {
                visited[r][c] = true;
                if (    srch(board, w, r, c + 1, index + 1, visited) ||
                        srch(board, w, r, c - 1, index + 1, visited) ||
                        srch(board, w, r - 1, c, index + 1, visited) ||
                        srch(board, w, r + 1, c, index + 1, visited) ) {
                    return true;
                }
                
                // 从当前位置未能搜索到结果。重置visited进行下一轮搜索
                for (int i = 0; i <= maxrow; i++) {
                    for (int j = 0; j <= maxcol; j++) {
                        visited[i][j] = false;
                    }
                }
                c++;
                if (c > maxcol) {
                    c = 0;
                    r++;
                }
            }
        }
        return false;
    }
}
