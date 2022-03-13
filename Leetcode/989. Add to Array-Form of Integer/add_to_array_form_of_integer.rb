# Leetcode 989. Add to Array-Form of Integer
# https://leetcode.com/problems/add-to-array-form-of-integer/

# @param {Integer[]} num
# @param {Integer} k
# @return {Integer[]}
def add_to_array_form(num, k)
    result = Array.new
    
    carry = false
    i = num.length - 1
    while i >= 0 and k > 0
        sum = num[i] + (k % 10)
        k = k / 10
        
        if carry == true
            sum += 1
            carry = false
        end
        
        if sum >= 10
            sum = sum % 10
            carry = true
        end
        
        result.push(sum)
        i -= 1
    end
    
    while i >= 0
        sum = num[i];
        if carry == true
            carry = false
            sum += 1
        end
        
        if sum >= 10
            sum = sum % 10
            carry = true
        end 
        result.push(sum)
        i -= 1
    end
    
    while k > 0
        sum = k % 10
        if carry == true
            carry = false
            sum += 1
        end
        
        if sum >= 10
            sum = sum % 10
            carry = true
        end 
        result.push(sum)
        
        k = k / 10
    end
    
    if carry == true
        result.push(1)
    end
    
    result = result.reverse
    
    return result
end
