// Leetcode 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/
// time complexity: O(1) --> imo the computation cost is determined because the size of sudoku board is 9x9, it is constant 
// space complexity: O(1)

class Solution 
{
public:
    int getIndex(int row, int col)
    {
        if (row < 3)
        {
            if (col < 3)
            {
                return 0;
            }
            else if (col < 6)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if (row < 6)
        {
            if (col < 3)
            {
                return 3;
            }
            else if (col < 6)
            {
                return 4;
            }
            else
            {
                return 5;
            }
        }
        else
        {
            if (col < 3)
            {
                return 6;
            }
            else if (col < 6)
            {
                return 7;
            }
            else
            {
                return 8;
            }
        }
        
        return -1; // never reach here
    }
    
    bool check(vector<int>& cells, vector<int>& tblrow, vector<int>& tblcol, int row, int col, int num)
    {
        int index = getIndex(row, col);
        int b = (1 << num);
        return (cells[index] & b) == 0 && (tblrow[row] & b) == 0 && (tblcol[col] & b) == 0;
    }
    
    bool solve(vector<vector<char>>& board, vector<int>& cells, vector<int>& tblrow, vector<int>& tblcol, int row, int col)
    {
        if (row == 9)
        {
            return true; // reach the end
        }
        
        if (col == 9)
        {
            // go to next row
            return solve(board, cells, tblrow, tblcol, row + 1, 0);
        }
        
        if (board[row][col] == '.')
        {
            for (int n = 1; n <= 9; n++)
            {
                if (check(cells, tblrow, tblcol, row, col, n))
                {
                    board[row][col] = n + '0';
                    cells[getIndex(row, col)] |= (1 << n);
                    tblrow[row] |= (1 << n);
                    tblcol[col] |= (1 << n);

                    if (!solve(board, cells, tblrow, tblcol, row, col + 1))
                    {
                        // restore previous state
                        board[row][col] = '.';
                        cells[getIndex(row, col)] ^= (1 << n);
                        tblrow[row] ^= (1 << n);
                        tblcol[col] ^= (1 << n);
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            return solve(board, cells, tblrow, tblcol, row, col + 1);
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        vector<int> cells(9, 0); // bits, 8 ~ 0
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    int n = board[r][c] - '0';
                    int index = getIndex(r, c);
                    cells[index] |= (1 << n);
                    
                    row[r] |= (1 << n);
                    col[c] |= (1 << n);
                }
            }
        }
        
        solve(board, cells, row, col, 0, 0);
    }
};
