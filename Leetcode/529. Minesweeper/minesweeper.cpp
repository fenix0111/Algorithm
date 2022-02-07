// Leetcode 529. Minesweeper
// https://leetcode.com/problems/minesweeper/
// time complexity: O(n)
// space complexity: O(n)

// straightforward BFS
class Solution
{
public:
    bool isValid(const vector<int>& pos, int row, int col)
    {
        return pos[0] >= 0 && pos[0] < row && pos[1] >= 0 && pos[1] < col;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        int row = board.size();
        int col = board[0].size();
        
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return board;
        }
        
        queue<vector<int>> q;
        q.push({click[0], click[1]});
        while (!q.empty())
        {
            vector<int> pos = q.front();
            q.pop();
            
            if (board[pos[0]][pos[1]] == 'E')
            {
                board[pos[0]][pos[1]] = 'B';
            }
            
            vector<int> left = { pos[0], pos[1] - 1 };
            vector<int> right = { pos[0], pos[1] + 1 };
            vector<int> top = { pos[0] - 1, pos[1] };
            vector<int> bottom = { pos[0] + 1, pos[1] };
            
            vector<int> topleft = { pos[0] - 1, pos[1] - 1 };
            vector<int> topright = { pos[0] - 1, pos[1] + 1 };
            vector<int> bottomleft = { pos[0] + 1, pos[1] - 1 };
            vector<int> bottomright = { pos[0] + 1, pos[1] + 1 };
            
            // check if there are mines around current cell
            int mines = 0;
            if (isValid(left, row, col) && board[left[0]][left[1]] == 'M')
            {
                mines++;
            }
            if (isValid(right, row, col) && board[right[0]][right[1]] == 'M')
            {
                mines++;
            }
            if (isValid(top, row, col) && board[top[0]][top[1]] == 'M')
            {
                mines++;
            }
            if (isValid(bottom, row, col) && board[bottom[0]][bottom[1]] == 'M')
            {
                mines++;
            }
            if (isValid(topleft, row, col) && board[topleft[0]][topleft[1]] == 'M')
            {
                mines++;
            }
            if (isValid(bottomleft, row, col) && board[bottomleft[0]][bottomleft[1]] == 'M')
            {
                mines++;
            }
            if (isValid(topright, row, col) && board[topright[0]][topright[1]] == 'M')
            {
                mines++;
            }
            if (isValid(bottomright, row, col) && board[bottomright[0]][bottomright[1]] == 'M')
            {
                mines++;
            }
            
            // change current cell state
            if (mines > 0)
            {
                board[pos[0]][pos[1]] = ('0' + mines);
            }
            else
            {
                // add adjacent cells to the queue only when there is no mines around
                if (isValid(left, row, col))
                {
                    if (board[left[0]][left[1]] == 'E')
                    {
                        board[left[0]][left[1]] = 'B';
                        q.push(left);
                    }
                }

                if (isValid(right, row, col))
                {
                    if (board[right[0]][right[1]] == 'E')
                    {
                        board[right[0]][right[1]] = 'B';
                        q.push(right);
                    }
                }

                if (isValid(top, row, col))
                {
                    if (board[top[0]][top[1]] == 'E')
                    {
                        board[top[0]][top[1]] = 'B';
                        q.push(top);
                    }
                }

                if (isValid(bottom, row, col))
                {
                    if (board[bottom[0]][bottom[1]] == 'E')
                    {
                        board[bottom[0]][bottom[1]] = 'B';
                        q.push(bottom);
                    }
                }
                
                if (isValid(topleft, row, col))
                {
                    if (board[topleft[0]][topleft[1]] == 'E')
                    {
                        board[topleft[0]][topleft[1]] = 'B';
                        q.push(topleft);
                    }
                }
                
                if (isValid(topright, row, col))
                {
                    if (board[topright[0]][topright[1]] == 'E')
                    {
                        board[topright[0]][topright[1]] = 'B';
                        q.push(topright);
                    }
                }
                
                if (isValid(bottomleft, row, col))
                {
                    if (board[bottomleft[0]][bottomleft[1]] == 'E')
                    {
                        board[bottomleft[0]][bottomleft[1]] = 'B';
                        q.push(bottomleft);
                    }
                }
                
                if (isValid(bottomright, row, col))
                {
                    if (board[bottomright[0]][bottomright[1]] == 'E')
                    {
                        board[bottomright[0]][bottomright[1]] = 'B';
                        q.push(bottomright);
                    }
                }
            }
        }
        
        return board;
        
    }
};
