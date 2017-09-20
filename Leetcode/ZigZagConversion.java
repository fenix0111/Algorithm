// Leetcode 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/
// Runtime: 64ms

// 创建临时二维数组tmp, 以zigzag方式填充tmp，填完扫一遍。
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int len = s.length();
        
        // 列数 “len/2 + 1” 是大概凭感觉定的。。
        char[][] tmp = new char[numRows][len/2 + 1];

        int count = 0;
        int row = -1;
        int col = 0;
        
        // 是否到了底部拐角
        boolean diag = false;
        while (count < len) {
            if (diag) {
                row--;
                col++;
                tmp[row][col] = s.charAt(count);
                count++;

                if (row == 0) {
                    diag = false;
                }
            } else {
                row++;
                tmp[row][col] = s.charAt(count);
                count++;
                if (row == numRows - 1) {
                    diag = true;
                }
            }
        }

        int numCols = tmp[0].length;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (tmp[i][j] != 0) {
                    sb.append(tmp[i][j]);
                }
            }
        }
        return sb.toString();
    }
}
