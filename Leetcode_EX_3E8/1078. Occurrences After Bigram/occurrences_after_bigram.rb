# Leetcode 1078. Occurrences After Bigram
# https://leetcode.com/problems/occurrences-after-bigram/

# @param {String} text
# @param {String} first
# @param {String} second
# @return {String[]}
def find_ocurrences(text, first, second)
    result = Array.new
    text.split(' ').each_cons(3) do |words|
        if words[0].eql?(first) && words[1].eql?(second)
            result << words[2]
        end
    end
        
    return result
end
