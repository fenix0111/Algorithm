// Leetcode 419. Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board/
// time complexity: O(size of board)
// space complexity: O(1)

// because there is a premise said that "You receive a valid board"
// so no need to validate the board format

class Solution 
{
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        int row = board.size();
        int col = board[0].size();
        
        int count = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[r][c] == 'X')
                {
                    if (r == 0 && c == 0)
                    {
                        count++;
                        continue;
                    }
                    
                    if (r > 0 && c > 0)
                    {
                        if (board[r - 1][c] == '.' && board[r][c - 1] == '.')
                        {
                            count++;
                        }
                        continue;
                    }
                    
                    if (r == 0)
                    {
                        if (c > 0 && board[r][c - 1] == '.')
                        {
                            count++;
                        }
                        continue;
                    }
                    
                    if (c == 0)
                    {
                        if (r > 0 && board[r - 1][c] == '.')
                        {
                            count++;
                        }
                        continue;
                    }
                }
            }
        }
        
        return count;
    }
};
