# @param {String} s
# @return {String}
def remove_outer_parentheses(s)
    match = 0
    result = ""
    i = 0
    while i < s.length
        c = s[i]
        if c == '('
            if match > 0
                result +=c
            end
            match += 1
        else
            if match > 1
                result +=c
            end
            match -= 1
        end
        i += 1
    end
    
    return result
end
