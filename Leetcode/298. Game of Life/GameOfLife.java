// Leetcode 289. Game of Life
// 
// 

public class Solution {

    // 289. Game of Life
    public void gameOfLife(int[][] board) {
        int row = board.length;
        int col = board[0].length;

        int[][] temp = new int[row][col];

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                int liveNeibours = 0;

                int upleft_x = r - 1;
                int upleft_y = c - 1;

                int up_x = r - 1;
                int up_y = c;

                int upright_x = r - 1;
                int upright_y = c + 1;

                int left_x = r;
                int left_y = c - 1;

                int right_x = r;
                int right_y = c + 1;

                int down_x = r + 1;
                int down_y = c;

                int downleft_x = r + 1;
                int downleft_y = c - 1;

                int downright_x = r + 1;
                int downright_y = c + 1;

                if ((upleft_x >= 0 && upleft_y >= 0) && (upleft_x < row && upleft_y < col) && board[upleft_x][upleft_y] == 1) {
                    liveNeibours++;
                }

                if ((up_x >= 0 && up_y >= 0) && (up_x < row && up_y < col)  && board[up_x][up_y] == 1) {
                    liveNeibours++;
                }

                if ((upright_x >= 0 && upright_y >= 0) && (upright_x < row && upright_y < col)  && board[upright_x][upright_y] == 1) {
                    liveNeibours++;
                }

                if ((left_x >= 0 && left_y >= 0) && (left_x < row && left_y < col)  && board[left_x][left_y] == 1) {
                    liveNeibours++;
                }

                if ((right_x >= 0 && right_y >= 0) && (right_x < row && right_y < col)  && board[right_x][right_y] == 1) {
                    liveNeibours++;
                }

                if ((down_x >= 0 && down_y >= 0) && (down_x < row && down_y < col)  && board[down_x][down_y] == 1) {
                    liveNeibours++;
                }

                if ((downleft_x >= 0 && downleft_y >= 0) && (downleft_x < row && downleft_y < col)  && board[downleft_x][downleft_y] == 1) {
                    liveNeibours++;
                }

                if ((downright_x >= 0 && downright_y >= 0) && (downright_x < row && downright_y < col)  && board[downright_x][downright_y] == 1) {
                    liveNeibours++;
                }

                boolean isAlive = board[r][c] == 1 ? true : false;
                if (isAlive) {
                    if (liveNeibours < 2 || liveNeibours > 3) {
                        temp[r][c] = 0;
                    } else if (liveNeibours == 2 || liveNeibours == 3) {
                        temp[r][c] = 1;
                    }
                } else {
                    if (liveNeibours == 3) {
                        temp[r][c] = 1;
                    }
                }
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                board[r][c] = temp[r][c];
            }
        }

    }
}
