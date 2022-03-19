# Leetcode 1160. Find Words That Can Be Formed by Characters
# https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

# @param {String[]} words
# @param {String} chars
# @return {Integer}
def count_characters(words, chars)
    char_counts = Array.new(128, 0)
    i = 0
    while i < chars.length
        char_counts[chars[i].ord] += 1
        i += 1
    end
    
    result = 0
    words.each do |word|
        c = Array.new(128, 0)
        j = 0
        while j < word.length
            c[word[j].ord] += 1
            j += 1
        end
        
        j = 0
        can_form = true
        while j < 128
            if char_counts[j] < c[j]
                can_form = false
                break
            end
            
            j += 1
        end
        
        if can_form
            result += word.length
        end
    end
    
    return result
end
