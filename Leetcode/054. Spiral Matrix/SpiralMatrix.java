// Leetcode 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/description/
// Runtime: 3ms

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new LinkedList<>();

        if (matrix.length == 0) {
            return result;
        }

        if (matrix.length == 1) {
            for (int i = 0; i < matrix[0].length; i++) {
                result.add(matrix[0][i]);
            }
            return result;
        }

        if (matrix[0].length == 1) {
            for (int i = 0; i < matrix.length; i++) {
                result.add(matrix[i][0]);
            }
            return result;
        }

        int current_row = 0;
        int current_col = 0;
        int len_row = matrix.length;
        int len_col = matrix[0].length;
        int step_row = len_row;
        int step_col = len_col;
        int max = len_col * len_row;
        int count = 0;

        for (int i = 0; i < matrix[0].length; i++) {
            result.add(matrix[0][i]);
            current_col = i;
            count++;
        }

        boolean is_right_bottom = true;
        while ( (step_col > 0) && (step_row > 0) && (count < max) ) {
            if (is_right_bottom) {
                if (step_row > 0 && count < max) {
                    int cr = current_row;
                    for (int i = 1; i < step_row; i++) {
                        result.add(matrix[cr + i][current_col]);
                        current_row++;
                        count++;
                    }
                    step_row--;
                }
                
                if (step_col > 0  && count < max) {
                    int cl = current_col;
                    for (int j = 1; j < step_col; j++) {
                        result.add(matrix[current_row][cl - j]);
                        current_col--;
                        count++;
                    }
                    step_col--;
                }
                is_right_bottom = !is_right_bottom;
            } else {
                if (step_row > 0  && count < max) {
                    int cr = current_row;
                    for (int i = 1; i < step_row; i++) {
                        result.add(matrix[cr - i][current_col]);
                        current_row--;
                        count++;
                    }
                    step_row--;
                }

                if (step_col > 0  && count < max) {
                    int cl = current_col;
                    for (int j = 1; j < step_col; j++) {
                        result.add(matrix[current_row][cl + j]);
                        current_col++;
                        count++;
                    }
                    step_col--;
                }
                is_right_bottom = !is_right_bottom;
            }
        }

        return result;
    }
}
