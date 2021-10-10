// Leetcode 212. Word Search II
// https://leetcode.com/problems/word-search-ii/
// time complexity: ??
// space complexity: O(n)

class Solution
{
public:
    bool check(string& target, vector<vector<char>>& board,
               vector<vector<bool>>& visited,
               int row, int col, int i, int j, int idx)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
        {
            return false;
        }
        
        if (visited[i][j])
        {
            return false;
        }
        
        if (idx >= target.length())
        {
            return false;
        }
        
        if (target[idx] != board[i][j])
        {
            return false;
        }
        
        if (idx == target.length() - 1)
        {
            return true;
        }

        visited[i][j] = true;

        if (check(target, board, visited, row, col, i + 1, j, idx + 1))
        {
            visited[i][j] = false;
            return true;
        }

        if (check(target, board, visited, row, col, i, j + 1, idx + 1))
        {
            visited[i][j] = false;
            return true;
        }

        if (check(target, board, visited, row, col, i - 1, j, idx + 1))
        {
            visited[i][j] = false;
            return true;
        }

        if (check(target, board, visited, row, col, i, j - 1, idx + 1))
        {
            visited[i][j] = false;
            return true;
        }

        visited[i][j] = false;

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int row = board.size();
        int col = board[0].size();
        vector<string> result;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        // record apprearance of board character
        bool tbl[26] = { false };
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                tbl[board[r][c] - 'a'] = true;
            }
        }

        for (string& word : words)
        {
            // do screening first
            // if the word contains a character which doesn't appear in the board
            // then skip it
            bool valid = true;
            for (char c : word)
            {
                if (!tbl[c - 'a'])
                {
                    valid = false;
                    break;
                }
            }
            
            if (!valid)
            {
                continue;
            }
            bool found = false;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (word[0] == board[i][j] && check(word, board, visited, row, col, i, j, 0))
                    {
                        found = true;
                        result.push_back(word);
                        break;
                    }
                }

                if (found)
                {
                    break;
                }
            }
        }

        return result;
    }
};
