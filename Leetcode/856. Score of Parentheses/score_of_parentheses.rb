# @param {String} s
# @return {Integer}
LEFT = -1
RIGHT = 0
def score_of_parentheses(s)
    stack = Array.new
    i = 0
    while i < s.length
        if s[i] == ')'
            sum = 0
            while stack.last != LEFT
                sum += stack.last
                stack.pop
            end

            if sum == 0
                stack.pop
                stack << 1
            else
                stack.pop
                stack << sum * 2
            end
        else
            stack << LEFT
        end
        i += 1
    end
    
    return stack.sum
end
