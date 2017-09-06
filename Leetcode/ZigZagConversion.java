// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/
// Runtime: 64ms

class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int len = s.length();
        char[][] tmp = new char[numRows][len/2 + 1];

        int count = 0;
        int row = -1;
        int col = 0;
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
    
    // 网上41ms解法
    public String convert(String s, int numRows) {
        if(numRows <= 1) 
            return s;
        StringBuilder result = new StringBuilder();  
        int step = numRows * 2 - 2;
        int shift = step+2, cur = 0, len = s.length();
        for(int i = 0; i < numRows; i ++) {
            cur = i;
            shift -= 2;
            
            while(cur < len) {
                result.append(s.charAt(cur));
                if(i != 0 && i != (numRows-1) && (cur + shift) < len) {
                    result.append(s.charAt(cur+shift)); 
                } 
                cur += step;
            }  
        }
        return result.toString();
    }
}
