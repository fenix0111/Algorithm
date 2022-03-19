# Leetcode 1128. Number of Equivalent Domino Pairs
# https://leetcode.com/problems/number-of-equivalent-domino-pairs/

# @param {Integer[][]} dominoes
# @return {Integer}

def get_pairs(n)
    if n == 2
        return 1
    end
    
    return get_pairs(n - 1) + (n - 1)
end

def num_equiv_domino_pairs(dominoes)
    counter = {}
    dominoes.each do |domino|
        small = domino.min
        big = domino.max
        key = small << 16
        key |= big
        
        if counter.include?(key)
            counter[key] += 1
        else
            counter[key] = 1
        end
    end
    
    result = 0
    counter.each do |k, v|
        if v > 1
            result += get_pairs(v)
        end
    end
    
    return result
end
