// Leetcode 79. Word Search
// https://leetcode.com/problems/word-search/
// time complexity: TBD
// space complexity: O(size of board) --> for visited table

class Solution 
{
public:
    bool run(vector<vector<bool>>& visited, int idx, string& word, vector<vector<char>>& board, int r, int c)
    {
        int row = board.size();
        int col = board[0].size();
        
        if (r >= row || c >= col || r < 0 || c < 0)
        {
            return false;
        }
        
        if (visited[r][c])
        {
            return false;
        }
        
        if (word[idx] != board[r][c])
        {
            return false;
        }
        
        if (idx == word.length() - 1)
        {
            return true;
        }
        
        visited[r][c] = true;
        
        if (run(visited, idx + 1, word, board, r + 1, c)) 
            return true;
        
        if (run(visited, idx + 1, word, board, r - 1, c))
            return true;
        
        if (run(visited, idx + 1, word, board, r, c + 1))
            return true;
        
        if (run(visited, idx + 1, word, board, r, c - 1))
            return true;
        
        visited[r][c] = false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int row = board.size();
        if (row == 0)
        {
            return false;
        }
        
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (run(visited, 0, word, board, r, c))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
