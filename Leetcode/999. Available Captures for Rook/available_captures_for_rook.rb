# Leetcode 999. Available Captures for Rook
# https://leetcode.com/problems/available-captures-for-rook/

# @param {Character[][]} board
# @return {Integer}

PAWN = 'p'
BISHOP = 'B'
ROOK = 'R'

def num_rook_captures(board)
    r = 0
    c = 0
    
    board.each_with_index do |row, i|
        row.each_with_index do |col, j|
            if row[j] == ROOK
                r = i
                c = j
            end
        end
    end
    
    result = 0
    
    # up
    i = r
    while i >= 0
        if board[i][c] == BISHOP
            break
        end
        
        if board[i][c] == PAWN
            result += 1
            break;
        end
        i -= 1
    end
    
    # down
    i = r
    while i < 8
        if board[i][c] == BISHOP
            break
        end
        
        if board[i][c] == PAWN
            result += 1
            break;
        end
        i += 1
    end
    
    #left
    i = c
    while i >= 0
        if board[r][i] == BISHOP
            break
        end
        
        if board[r][i] == PAWN
            result += 1
            break;
        end
        i -= 1
    end
    
    #right
    i = c
    while i < 8
        if board[r][i] == BISHOP
            break
        end
        
        if board[r][i] == PAWN
            result += 1
            break;
        end
        i += 1
    end
    
    return result
end
