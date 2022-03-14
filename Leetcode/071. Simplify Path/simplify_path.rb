# @param {String} path
# @return {String}
def is_alphanum(c)
    return (c >= '0' && c <= '9') || 
    (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'
    
end

def simplify_path(path)
    stack = Array.new
    i = 1
    while i < path.length
        str = ""
        while i < path.length && path[i] != '/'
            str << path[i]
            i += 1
        end
        
        if str.length > 0
            if str == ".."
                if stack.any?
                    stack.pop
                end
            elsif str != "."
                stack.push(str)
            end
        end
        
        i += 1
    end
    
    result = "/"
    i = 0
    while i < stack.length
        result << stack[i]
        result << "/"
        i += 1
    end
    
    if result.length > 1
        result = result.chop
    end
    
    return result
end
