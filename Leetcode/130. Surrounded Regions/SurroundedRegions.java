// Leetcode 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/description/
// Runtime: 11ms

// Using DFS, similar to the Islands problem.
class Solution {
    class Cord {
        public int X = 0;
        public int Y = 0;
        public Cord(int x, int y) {
            this.X = x;
            this.Y = y;
        }
    }
    
    boolean solveDFS(char[][] board, int r, int c, ArrayDeque<Cord> list, boolean[][] visited) {
        char O = 'O';
        char X = 'X';
        int numRow = board.length;
        int numCol = board[0].length;
        
        // found O on the boundary
        if (board[r][c] == O && (r == 0 || r == numRow - 1 || c == 0 || c == numCol - 1)) {
            // color it, don't come back here
            visited[r][c] = true;
            return false;
        }
        
        if (board[r][c] == X) {
            return true;
        }

        if (board[r][c] == O && visited[r][c] == false) {
            visited[r][c] = true;
           
            // left
            boolean bl = solveDFS(board, r,     c - 1, list, visited);
            
            // top
            boolean bt = solveDFS(board, r - 1, c,     list, visited);
            
            // right
            boolean br = solveDFS(board, r,     c + 1, list, visited);
            
            // bottom
            boolean bb = solveDFS(board, r + 1, c,     list, visited);
            
            if (bl && bt && br && bb) {
                Cord cord = new Cord(r, c);
                list.add(cord);
                return true;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    public void solve(char[][] board) {
        char O = 'O';
        char X = 'X';
        
        if (null == board || board.length == 0) {
            return;
        }
        
        int numRow = board.length;
        int numCol = board[0].length;
        
        // like 1x1 or 2x2 could never make it
        if (numRow < 3 || numCol < 3) {
            return;
        }
        
        ArrayDeque<Cord> readyForColorList = new ArrayDeque<>();
        
        boolean[][] visited = new boolean[numRow][numCol];
        for (int r = 0; r < numRow; r++) {
            for (int c = 0; c < numCol; c++) {
                visited[r][c] = false;
            }
        }
        
        for (int r = 1; r < numRow - 1; r++) {
            for (int c = 1; c < numCol - 1; c++) {
                if (board[r][c] == O && visited[r][c] == false) {
                    boolean verified = solveDFS(board, r, c, readyForColorList, visited);
                    
                    if (verified) {
                        // flip
                        while (!readyForColorList.isEmpty()) {
                            Cord cord = readyForColorList.removeFirst();
                            int x = cord.X;
                            int y = cord.Y;
                            
                            board[x][y] = X;
                        }
                    } else {
                        readyForColorList.clear();
                    }
                }
            }
        } 
    }
}
